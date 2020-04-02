#pragma once
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;
class NhanVien
{
protected:
	string id;
	string name;
	Date date;
	double salary;
	bool gioitinh;

public:
	NhanVien();
	~NhanVien();
	void setId(string ID);
	void setName(string Name);
	void setDate(Date D);
	void setGioiTinh(bool Gioitinh);
	string getName();
	string getId();
	Date getDate();
	bool getGioiTinh();
	virtual void  Nhap();
	virtual void  Xuat();
	virtual double Luong() = 0;
};