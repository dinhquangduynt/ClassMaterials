#include<iostream>
#include<string>
using namespace std;
#pragma once
class Date
{
public: int ngay, thang, nam;
public:
	void Nhapdate();
	void Xuatdate();
	Date(int ngay = 0, int thang = 10, int nam = 2018);
	void show();
	friend ostream &operator<<(ostream &, const Date &);
	friend istream &operator>>(istream &, Date &);
	~Date();
};

