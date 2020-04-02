
#include "NhanVien.h"
#pragma once

class List
{
public:
	NhanVien *data;
	int n;
public:
	List(int n = 1);
	void Show();
	friend ostream &operator<<(ostream &, const List &);
	friend istream &operator>>(istream &, List &);
	NhanVien &operator[] (int);
	void Themdau(NhanVien &);
	void Themcuoi(NhanVien &);
	void Thembatki(NhanVien &, int);
	void Capnhat(string);
	void Xoadau();
	void Xoacuoi();
	void Xoabatki(int);
	void shellsort(bool(*)(double, double));
	void Sapxep();
	NhanVien Binarysearch(NhanVien &, double);
	//List Binarysearch(List, double);

	~List();
};

