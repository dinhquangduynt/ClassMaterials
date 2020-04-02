#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "SinhVien.h"

class Node
{
private:
	SinhVien data;
	Node *next;

public:
	Node();
	~Node();
	void Nhap();
	void Xuat();
	void setnext(Node*);
	Node *getnext();
	SinhVien getdata();

};

