#pragma once

#include "Node.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class RLE_HUFF
{
public:
	RLE_HUFF(void);
	// Проверка корректности текста представляющего кодировку в формате RLE
	static bool IsCorrectRleEncode(String ^encode);
	// RLE кодирование
	static String^ RleEncode(String ^text);
	// RLE декодирование
	static String ^ RleDecode(String ^encode);
	// Построение результирующей таблицы Хаффмана по готовому дереву частот символов
private: 
	static String ^BuildTable(Node ^root, Dictionary<Char, String^ > ^table, String ^cur_code);
	// Построение таблицы Хаффмана по заданой строке текста
public: 
	static Dictionary<Char, String^>^ GetHuffmanTable(String ^text);
	// Раскодирование по Хаффману
	static String^ HuffmanDecode(String ^encode, Dictionary<String^, Char> ^table);
	// Кодирование по Хаффману
	static String^ HuffmanEncode(String ^text);
};