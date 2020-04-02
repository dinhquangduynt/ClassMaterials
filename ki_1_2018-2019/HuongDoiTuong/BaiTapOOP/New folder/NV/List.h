
#include "NhanVien.h"
#pragma once

class List
{
public:
	NhanVien *data;
	int n;
public:
	//List(int n = 2);
	void Show();
	friend ostream &operator<<(ostream &, const List &);
	friend istream &operator>>(istream &, List &);
	NhanVien &operator[] (int);
	void Themdau(NhanVien &);
	void Themcuoi(NhanVien &);
	void Thembatki(NhanVien &,int );
	void Capnhat(string);
	void Xoadau();
	void Xoacuoi();
	void Xoabatki(int);
	/*bool TD(double, double);
	bool GD(double, double);*/
	//void swap(NhanVien&, NhanVien&);
	void shellsort(bool (*)(double , double));
	void Sapxep();
	//int Binarysearch(double);
	NhanVien& Binarysearch1(NhanVien &,double);
	
	~List();
};

