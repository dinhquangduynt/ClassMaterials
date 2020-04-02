#pragma once
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;
class NhanVien:public Date
{
private:
	string id;
	string name;
	Date date;
	double salary;
	bool gioitinh;

public:
	NhanVien();
	~NhanVien();
	NhanVien(const NhanVien &nv);
	void setId(string ID);
	void setName(string Name);
	void setDate(Date D);
	void setSalary(double Salary);
	void setGioiTinh(bool Gioitinh);
	float getLuong() ;
	string getName();
	string getId();
	void operator =(const NhanVien nv);
	friend istream &operator >> (istream &is, NhanVien &nv);
	friend ostream &operator << (ostream &out, const NhanVien &nv);
};
