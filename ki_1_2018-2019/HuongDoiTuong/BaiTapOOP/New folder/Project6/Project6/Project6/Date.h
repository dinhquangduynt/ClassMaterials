#pragma once
#include<iostream>
using namespace std;
class Date
{
private:
	int ngay;
	int thang;
	int nam;
	char kt1, kt2;
public:
	~Date();
	Date(int Ngay = 1, char kt1 = '/', int Thang = 1, char kt2 = '/', int Nam = 1990);
	void setNgay(int Ngay);
	void setThang(int Thang);
	void setNam(int Nam);
	int getNgay();
	int getThang();
	int getNam();
	friend ostream &operator <<(ostream &out, const Date &x);
	friend istream &operator >> (istream &is, Date &x);
	bool KTNam();
};