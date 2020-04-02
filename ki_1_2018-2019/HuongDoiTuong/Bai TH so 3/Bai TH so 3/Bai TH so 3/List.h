#pragma once
#include"NODE.h"
class List
{
	NODE *p;
public:
	List();
	~List();
	void Init();
	NODE* CreateNode(SinhVien);
	void AddHead(NODE *);
	void AddTail(NODE *);
	void Input();
	void Output();
	void Insert();
	void Delete();
	void Search();
	void Sort();
	void Update();
};

