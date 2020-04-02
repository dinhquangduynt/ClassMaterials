#include "Node.h"



Node::Node()
{
}

Node::~Node()
{
}

void Node::Nhap()
{
	this->data.Nhap();
	next = NULL;
}

void Node::Xuat()
{
	this->data.Xuat();
}

void Node::setnext(Node * next)
{
	this->next = next;
}

Node * Node::getnext()
{
	return this->next;
}

SinhVien Node::getdata()
{
	return this->data;
}

