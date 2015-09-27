#include "Node.h"


Node::Node(void) 
{
	character = 0;
	count = 0;
	left = nullptr;
	right = nullptr;
}

Node::Node(int count, Char character)
{
	this->count = count;
	this->character = character;
	left = nullptr;
	right = nullptr;
}
Node::Node(Node ^lv, Node ^rv)
{
	this->count = lv->count + rv->count;
	this->character = L'';
	this->left = lv;
	this->right = rv;
}
int Node::CompareTo(Object ^object)
{
	Node ^rv = (Node^)object;
	if(count < rv->count) return -1;
	else if(count > rv->count) return 1;
	return 0;
}