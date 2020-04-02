#pragma once
#include<iostream>
#include <string>
using namespace std;
class SinhVien
{
public:
	string MSSV;
	string HoTen;
	int NamSinh;
public:
	SinhVien();
	~SinhVien();
	friend istream& operator >> (istream&, SinhVien&);
	friend ostream& operator << (ostream&, SinhVien&);
};

