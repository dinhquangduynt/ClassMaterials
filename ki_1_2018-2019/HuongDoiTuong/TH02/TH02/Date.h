#include<iostream>
using namespace std;
#pragma once
class Date
{
public: int ngay, thang, nam;
public:
	void Nhapdate();
	void Xuatdate();
	Date(int = 0, int = 10, int = 2018);
	void show();
	~Date();
};

