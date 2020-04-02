#include "NODE.h"
#include <string.h>
using namespace std;
#pragma once
class QLNV
{
public:
	NODE *head;
	NODE *tail;
	int n=0;
	string TQL;
public:
	QLNV();
	~QLNV();
	NODE * CreateNode(NhanVien*);
	void Init();
	bool IsEmpty(QLNV&);
	void Addhead(NODE&);
	void Addtail(NODE*);
	void Add(NODE*);
	//void Nhap();
	//void Xuat();
	void Deletehead();
	void Deletetail();
	void Delete();
	void Search();
	void Update();
	//NODE * mid(QLNV l);
	//void shellsort(bool(*)(string, string));
	//void Sapxep();
	friend ostream &operator<<(ostream &, const QLNV &);
	friend istream &operator>>(istream &, QLNV &);
	NODE operator[](int);
};

