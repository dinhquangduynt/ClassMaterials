#pragma once
#include"CongTrinhKhoaHoc.h"
#include<iostream>
using namespace std;
class Sach:public CongTrinhKhoaHoc
{
private:
	string loaisach;
public:
	Sach();
	~Sach();
	Sach(const Sach &);
	void Nhap();
	void Xuat();
};

