#include"date.h"
#include<iostream>
using namespace std;

#pragma once
using namespace std;

class NhanVien
{
public:
	string MSNV, Name;
	double Luong;
	bool GioiTinh;
	Date Ngay;

public:
	NhanVien(string = "12345678", string = "abc", bool = 0, double = 123, Date = Date(1, 2, 3));
	void Nhap();
	void Xuat();
	~NhanVien();
};
