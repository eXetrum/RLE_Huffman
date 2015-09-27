#include "RLE_HUFF.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

RLE_HUFF::RLE_HUFF(void) {}

// Проверка корректности текста представляющего кодировку в формате RLE
bool RLE_HUFF::IsCorrectRleEncode(String ^encode)
{
	// Списки чисел и символов
	ArrayList ^numbers = gcnew ArrayList();
	ArrayList ^characters = gcnew ArrayList();
	// Строка "число"
	String ^dg = "";
	String ^ch = "";
	if(!Char::IsDigit(encode[0])) return false;
	// Цикл разбора содержимого кодировки
	for(int i = 0; i < encode->Length; i++)
    {
		// Встретили число в строке
		if (Char::IsDigit(encode[i]))
		{
			// Добавляем "цифру" к числу
			dg += encode[i];
			// Если нужно добавляем строку символов к списку
			if(ch->Length)
			{
				characters->Add(ch);
				ch = "";
			}
		}
		// Встретили не цифру
        else
        {
			// Собираем в строку символов
			ch += encode[i];
			// Если строка содержащая представление числа не пуста
			if(dg->Length)
			{
				// Разбираем содержимое строки преобразуя в число и добавляем к списку
				numbers->Add(Int16::Parse(dg));
				// Обнуляем строку
				dg = "";
			}			
        }
    }
	if(ch->Length > 0) characters->Add(ch);
	if(dg->Length > 0) numbers->Add(dg);

	// Все символы в списке символов должны иметь единичную длинну 
	for (int i = 0; i < characters->Count; i++)
	{
		if(((String^)characters[i])->Length > 1) return false;
	}
	// На выходе количество элементов списков чисел и символов должно быть одинаковым
	return numbers->Count == characters->Count;
}
// RLE кодирование
String^ RLE_HUFF::RleEncode(String ^text)
{
	// Строка результат кодирования
	String ^encode;
	// Счетчик повторов
	int count = 1;
	// Запоминаем первую букву
	wchar_t current = text[0];
	// Цикл прохода строки и подсчета повторяющихся элементов
	for(int i = 1; i < text->Length; i++)
	{
		// Если встретили повтор - увеличиваем счетчик повторов
		if (current == text[i]) count++;
		// Если встретили новый символ
		else
		{
			// Добавляем данные о повторе предыдущего символа к результату
			encode += String::Format("{0}{1}", count, current);
			// Счетчик повторов сбрасываем
			count = 1;
			// Запоминаем новый символ для подсчета повторов
			current = text[i];
		}
	}
	// Завершаем подсчет
	encode += String::Format("{0}{1}", count, current);
	// Возвращаем результат
	return encode;
}
// RLE декодирование
String^ RLE_HUFF::RleDecode(String ^encode)
{
	// Результирующий текст
	String ^text;
	// 
	String ^digit = "";
    int count = 0;
	wchar_t current;
	for(int i = 0; i < encode->Length; i++)
    {
        current = encode[i];
		
		if (Char::IsDigit(current)) digit += current;
        else
        {
			count = Int16::Parse(digit);
            digit = "";
            for (int j = 0; j < count; j++)
                text += current;
        }
    }
    return text;
}
// Рекурсивная функция построения таблицы по готовому бинарному дереву
String ^RLE_HUFF::BuildTable(Node ^root, Dictionary<Char, String^ > ^table, String ^cur_code)
{
	// Если есть левый потомок
	if(root->left != nullptr)
	{
		// Добавляем нуль к результату
		cur_code += "0";
		// Спускаемся по левой ветке
		cur_code = BuildTable(root->left, table, cur_code);
	}
	// Если есть правый потомок
	if(root->right != nullptr)
	{
		// Добавляем к результату единицу
		cur_code += "1";
		// Спускаемся по правой ветке
		cur_code =  BuildTable(root->right, table, cur_code);
	}
	// Если у узла задан символ (узел является листом)
	if(root->character != 0) table->Add(root->character, (cur_code=="") ? "0" : cur_code); // Сборка кода для текущего символа завершена -> добавляем в таблицу
	// Откидываем последий символ (поднимаемся в узле на верх)
	if(cur_code->Length != 0)
	cur_code = cur_code->Substring(0, cur_code->Length - 1);
	return cur_code;
}
// Построение таблицы по заданному тексту
Dictionary<Char, String^>^ RLE_HUFF::GetHuffmanTable(String ^text)
{
	// Словарь частот
	Dictionary<Char, int> ^freq = gcnew Dictionary<Char, int>();

	// Собираем информацию о частотах каждого символа
	for(int i = 0; i < text->Length; i++)
	{
		// Получаем символ
		Char key = text[i];
		// Если уже есть в таблице
		if(freq->ContainsKey(key)) freq[key]++; // Просто увеличим счетчик
		// Если нету - добавляем символ в таблицу и количество обозначаем единицей
		else freq->Add(key, 1);
	}
	// Список - бинарное дерево
	List<Node^> ^list = gcnew List<Node^>();
	// Добавляем данные таблицы частот в список
	for each (KeyValuePair<Char, int> var in freq)
		list->Add(gcnew Node(var.Value, var.Key));

	List<Node^> ^work = gcnew List<Node^>(list);
	// Строим дерево
	while(list->Count > 1)
	{
		// Сортируем текущий список
		list->Sort();
		// Получаем два узла с наименьшим значением частоты
		Node ^left = list[0]; list->RemoveAt(0);
		Node ^right = list[0]; list->RemoveAt(0);
		// Объединяем узлы под одним родителем, значение частоты вхождения обоих символов складывается
		Node ^parent = gcnew Node(left, right);
		// Добавляем вместо двух узлов один "склеенный"
		list->Add(parent);
	}
	// После построения список состоит из одного элемента - корень дерева
	//Node ^root = list[0];
	// Создаем таблицу код - символ
	Dictionary<Char, String^> ^table = gcnew Dictionary<Char, String^>();
	// Временная строка
	String ^code = "";
	Node ^root = list[0];
	// Строим Таблицу кодов для каждого символа
	BuildTable(list[0], table, code);
	// Возвращаем построенную таблицу
	return table;
}
// Хаффман декодирование
String^ RLE_HUFF::HuffmanDecode(String ^encode, Dictionary<String^, Char> ^table)
{
	String ^text = "";
	try
	{		
		// Слово для поиска в списке кодов
		String ^word = "";
		// Текущий символ полученный по собранному коду
		Char c;
		// Пока в строке есть кодированные символы
		while(encode->Length >= 0)
		{
			// Обнуляем счетчик
			int count = 0;
			// Ищем в таблице строку с единственным вхождением
			for each (KeyValuePair<String^, Char> var in table)
			{
				// Если нашли вхождение
				if(var.Key->StartsWith(word))
				{
					// Запоминаем символ для текущего кода
					c = var.Value;
					// Счетчик совпадений увеличим
					count++;
				}
			}
			// Если для текущего кода вхождение было единично
			if(count == 1)
			{
				// И длина кода не нулевая
				if(word->Length > 0)
				{
					// Добавляем символ к результату
					text += c;
				}
				// Обнуляем код символа
				c = 0;
				// Проверяем не закончились ли символы
				if(encode->Length == 0) break;
				// Получаем первый символ
				word = "" + encode[0];
				// Отсекаем полученный символ
				encode = encode->Remove(0, 1);
			}
			// Если вхождение множественное - нужно уточнить код для символа до тех пор пока не будет единственное вхождение
			else
			{
				if(encode->Length == 0) break;
				// Расширяем код
				word += encode[0];
				// Отсекаем от строки
				encode = encode->Remove(0, 1);
			}
		
		}
	}
	catch(Exception ^ex)
	{
		return ex->Message;
	}
	// Возвращаем результат
	return text;
}
//
String^ RLE_HUFF::HuffmanEncode(String^ text)
{
	// Построили таблицу
	Dictionary<Char, String^> ^table = RLE_HUFF::GetHuffmanTable(text);
	String ^encode = "";
	Char buff = 0;
	int count = 0;
	// Собрали результат
	for(int i = 0; i < text->Length; i++)
	{
		encode +=  table[text[i]];
		/*String ^binary = table[text[i]];

		for(int j = 0; j < binary->Length; j++)
		{
			buff = buff | binary[j] << (7 - count);
			count++;
			if(count == 8)
			{
				count = 0;
				encode += buff;
				buff = 0;
			}
		}
		encode += binary;*/
	}
	return encode;
}