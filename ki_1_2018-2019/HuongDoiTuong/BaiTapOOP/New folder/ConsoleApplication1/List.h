#pragma once
#include"NhanVien.h"
#include<iostream>
#include<string>
using namespace std;

class List
{
private:
	NhanVien *ds;
	int n;
public:
	List();
	~List();
	List(int n, NhanVien *ds);
	void OutputList();
	void CapNhat();
	void AddFirst();
	void AddLast();
	void AddAnyLocation();
	void DeleteFirst();
	void DeleteLast();
	void DeleteAnyLocation();
	int TimKiem(NhanVien *p, int  N, float L);
	void SapXep(NhanVien *p, int n , bool ComFunct(float, float));
	void LuaChonSapXep();
	void InTimKiem();
	NhanVien &operator [](int i);
	friend ostream &operator <<(ostream &out, List &list);
};

