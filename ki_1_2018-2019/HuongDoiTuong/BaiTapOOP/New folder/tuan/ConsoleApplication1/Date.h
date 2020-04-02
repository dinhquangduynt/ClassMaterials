#pragma once
#include<iostream>
using namespace std;
class Date
{
private:
	int ngay;
	int thang;
	int nam;
public:
	~Date();
	Date(int Ngay = 1, int Thang = 1, int Nam = 1);
	void setNgay(int Ngay);
	void setThang(int Thang);
	void setNam(int Nam);
	friend ostream &operator <<(ostream &out, const Date &x);
	friend istream &operator >> (istream &is, Date &x);
};

