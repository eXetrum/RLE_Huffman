#pragma once
using System::IComparable;
using System::Char;

ref class Node : IComparable
{
public:
	Node(void);
	Node(int count, Char character);
	Node(Node ^lv, Node ^rv);
	virtual int CompareTo(Object ^object);
	// ����������
	int count;
	// ������
	Char character;
	// ������ � ����� �������
	Node ^left, ^right;
};