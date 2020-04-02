#include<iostream>
#include<string>
using namespace std;
#pragma once
class Date
{
private: int ngay, thang, nam;
public:
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int);
	void setThang(int);
	void setNam(int);
	void Nhapdate();
	void Xuatdate();
	Date(int = 10, int = 10, int = 2018);
	void show();
	friend ostream &operator<<(ostream &, const Date &);
	friend istream &operator>>(istream &, Date &);
	~Date();
};

