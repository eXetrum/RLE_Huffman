#include "RLE_HUFF.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

RLE_HUFF::RLE_HUFF(void) {}

// �������� ������������ ������ ��������������� ��������� � ������� RLE
bool RLE_HUFF::IsCorrectRleEncode(String ^encode)
{
	// ������ ����� � ��������
	ArrayList ^numbers = gcnew ArrayList();
	ArrayList ^characters = gcnew ArrayList();
	// ������ "�����"
	String ^dg = "";
	String ^ch = "";
	if(!Char::IsDigit(encode[0])) return false;
	// ���� ������� ����������� ���������
	for(int i = 0; i < encode->Length; i++)
    {
		// ��������� ����� � ������
		if (Char::IsDigit(encode[i]))
		{
			// ��������� "�����" � �����
			dg += encode[i];
			// ���� ����� ��������� ������ �������� � ������
			if(ch->Length)
			{
				characters->Add(ch);
				ch = "";
			}
		}
		// ��������� �� �����
        else
        {
			// �������� � ������ ��������
			ch += encode[i];
			// ���� ������ ���������� ������������� ����� �� �����
			if(dg->Length)
			{
				// ��������� ���������� ������ ���������� � ����� � ��������� � ������
				numbers->Add(Int16::Parse(dg));
				// �������� ������
				dg = "";
			}			
        }
    }
	if(ch->Length > 0) characters->Add(ch);
	if(dg->Length > 0) numbers->Add(dg);

	// ��� ������� � ������ �������� ������ ����� ��������� ������ 
	for (int i = 0; i < characters->Count; i++)
	{
		if(((String^)characters[i])->Length > 1) return false;
	}
	// �� ������ ���������� ��������� ������� ����� � �������� ������ ���� ����������
	return numbers->Count == characters->Count;
}
// RLE �����������
String^ RLE_HUFF::RleEncode(String ^text)
{
	// ������ ��������� �����������
	String ^encode;
	// ������� ��������
	int count = 1;
	// ���������� ������ �����
	wchar_t current = text[0];
	// ���� ������� ������ � �������� ������������� ���������
	for(int i = 1; i < text->Length; i++)
	{
		// ���� ��������� ������ - ����������� ������� ��������
		if (current == text[i]) count++;
		// ���� ��������� ����� ������
		else
		{
			// ��������� ������ � ������� ����������� ������� � ����������
			encode += String::Format("{0}{1}", count, current);
			// ������� �������� ����������
			count = 1;
			// ���������� ����� ������ ��� �������� ��������
			current = text[i];
		}
	}
	// ��������� �������
	encode += String::Format("{0}{1}", count, current);
	// ���������� ���������
	return encode;
}
// RLE �������������
String^ RLE_HUFF::RleDecode(String ^encode)
{
	// �������������� �����
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
// ����������� ������� ���������� ������� �� �������� ��������� ������
String ^RLE_HUFF::BuildTable(Node ^root, Dictionary<Char, String^ > ^table, String ^cur_code)
{
	// ���� ���� ����� �������
	if(root->left != nullptr)
	{
		// ��������� ���� � ����������
		cur_code += "0";
		// ���������� �� ����� �����
		cur_code = BuildTable(root->left, table, cur_code);
	}
	// ���� ���� ������ �������
	if(root->right != nullptr)
	{
		// ��������� � ���������� �������
		cur_code += "1";
		// ���������� �� ������ �����
		cur_code =  BuildTable(root->right, table, cur_code);
	}
	// ���� � ���� ����� ������ (���� �������� ������)
	if(root->character != 0) table->Add(root->character, (cur_code=="") ? "0" : cur_code); // ������ ���� ��� �������� ������� ��������� -> ��������� � �������
	// ���������� �������� ������ (����������� � ���� �� ����)
	if(cur_code->Length != 0)
	cur_code = cur_code->Substring(0, cur_code->Length - 1);
	return cur_code;
}
// ���������� ������� �� ��������� ������
Dictionary<Char, String^>^ RLE_HUFF::GetHuffmanTable(String ^text)
{
	// ������� ������
	Dictionary<Char, int> ^freq = gcnew Dictionary<Char, int>();

	// �������� ���������� � �������� ������� �������
	for(int i = 0; i < text->Length; i++)
	{
		// �������� ������
		Char key = text[i];
		// ���� ��� ���� � �������
		if(freq->ContainsKey(key)) freq[key]++; // ������ �������� �������
		// ���� ���� - ��������� ������ � ������� � ���������� ���������� ��������
		else freq->Add(key, 1);
	}
	// ������ - �������� ������
	List<Node^> ^list = gcnew List<Node^>();
	// ��������� ������ ������� ������ � ������
	for each (KeyValuePair<Char, int> var in freq)
		list->Add(gcnew Node(var.Value, var.Key));

	List<Node^> ^work = gcnew List<Node^>(list);
	// ������ ������
	while(list->Count > 1)
	{
		// ��������� ������� ������
		list->Sort();
		// �������� ��� ���� � ���������� ��������� �������
		Node ^left = list[0]; list->RemoveAt(0);
		Node ^right = list[0]; list->RemoveAt(0);
		// ���������� ���� ��� ����� ���������, �������� ������� ��������� ����� �������� ������������
		Node ^parent = gcnew Node(left, right);
		// ��������� ������ ���� ����� ���� "���������"
		list->Add(parent);
	}
	// ����� ���������� ������ ������� �� ������ �������� - ������ ������
	//Node ^root = list[0];
	// ������� ������� ��� - ������
	Dictionary<Char, String^> ^table = gcnew Dictionary<Char, String^>();
	// ��������� ������
	String ^code = "";
	Node ^root = list[0];
	// ������ ������� ����� ��� ������� �������
	BuildTable(list[0], table, code);
	// ���������� ����������� �������
	return table;
}
// ������� �������������
String^ RLE_HUFF::HuffmanDecode(String ^encode, Dictionary<String^, Char> ^table)
{
	String ^text = "";
	try
	{		
		// ����� ��� ������ � ������ �����
		String ^word = "";
		// ������� ������ ���������� �� ���������� ����
		Char c;
		// ���� � ������ ���� ������������ �������
		while(encode->Length >= 0)
		{
			// �������� �������
			int count = 0;
			// ���� � ������� ������ � ������������ ����������
			for each (KeyValuePair<String^, Char> var in table)
			{
				// ���� ����� ���������
				if(var.Key->StartsWith(word))
				{
					// ���������� ������ ��� �������� ����
					c = var.Value;
					// ������� ���������� ��������
					count++;
				}
			}
			// ���� ��� �������� ���� ��������� ���� ��������
			if(count == 1)
			{
				// � ����� ���� �� �������
				if(word->Length > 0)
				{
					// ��������� ������ � ����������
					text += c;
				}
				// �������� ��� �������
				c = 0;
				// ��������� �� ����������� �� �������
				if(encode->Length == 0) break;
				// �������� ������ ������
				word = "" + encode[0];
				// �������� ���������� ������
				encode = encode->Remove(0, 1);
			}
			// ���� ��������� ������������� - ����� �������� ��� ��� ������� �� ��� ��� ���� �� ����� ������������ ���������
			else
			{
				if(encode->Length == 0) break;
				// ��������� ���
				word += encode[0];
				// �������� �� ������
				encode = encode->Remove(0, 1);
			}
		
		}
	}
	catch(Exception ^ex)
	{
		return ex->Message;
	}
	// ���������� ���������
	return text;
}
//
String^ RLE_HUFF::HuffmanEncode(String^ text)
{
	// ��������� �������
	Dictionary<Char, String^> ^table = RLE_HUFF::GetHuffmanTable(text);
	String ^encode = "";
	Char buff = 0;
	int count = 0;
	// ������� ���������
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