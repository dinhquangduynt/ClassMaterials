#pragma once
#include<iostream>
#include"queue.h"
#include"CongTrinhKhoaHoc.h"
#include"BaiBao.h"
#include"Sach.h"
#include<string>
using namespace std;
class ListCTKH
{
private:
	string tenTG;
	int soCTKH;
	queue q;
public:
	ListCTKH();
	~ListCTKH();
	int getN();
	ListCTKH(const ListCTKH &);
	void operator =(const ListCTKH s);
	ListCTKH &operator [](int i);
	friend istream &operator >> (istream &i, ListCTKH &s);
	friend ostream &operator << (ostream &o, const ListCTKH &s);
	//void Xemtt();
	void Nhap();
	void Xuat();
	void Them();
	void Xoa();
	void TimKiem();
	void CapNhat();
};

