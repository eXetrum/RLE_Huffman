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
	// �������� ������������ ������ ��������������� ��������� � ������� RLE
	static bool IsCorrectRleEncode(String ^encode);
	// RLE �����������
	static String^ RleEncode(String ^text);
	// RLE �������������
	static String ^ RleDecode(String ^encode);
	// ���������� �������������� ������� �������� �� �������� ������ ������ ��������
private: 
	static String ^BuildTable(Node ^root, Dictionary<Char, String^ > ^table, String ^cur_code);
	// ���������� ������� �������� �� ������� ������ ������
public: 
	static Dictionary<Char, String^>^ GetHuffmanTable(String ^text);
	// �������������� �� ��������
	static String^ HuffmanDecode(String ^encode, Dictionary<String^, Char> ^table);
	// ����������� �� ��������
	static String^ HuffmanEncode(String ^text);
};