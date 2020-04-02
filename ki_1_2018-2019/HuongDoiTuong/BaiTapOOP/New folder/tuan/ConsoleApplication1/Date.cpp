#include "stdafx.h"
#include "Date.h"
#include<iostream>
#include<string>
using namespace std;


Date::~Date()
{
}

Date::Date(int Ngay, int Thang, int Nam)
{
}

void Date::setNgay(int Ngay)
{
	this->ngay = Ngay;
}

void Date::setThang(int Thang)
{
	this->thang = Thang;
}

void Date::setNam(int Nam)
{
	this->nam = Nam;
}

ostream & operator<<(ostream & out, const Date & x)
{
	out << x.ngay << "/" << x.thang << "/" << x.nam;
	return out;
}

istream & operator >> (istream & is, Date & x)
{
	int kt;
	do {
		kt = 1;
		is >> x.ngay;
		is >> x.thang;
		is >> x.nam;

		if (x.thang < 0 || x.thang > 12)
		{
			kt = 0;
		}
		if ((x.nam % 4 == 0 && x.nam % 100 != 0) || x.nam % 400 == 0)
		{
			if (x.thang == 2 && (x.ngay < 0 || x.ngay > 29))
			{
				kt = 0;
			}
		}
		else
		{
			if (x.thang == 2 && (x.ngay < 0 || x.ngay > 28))
			{
				kt = 0;
			}
			if ((x.thang == 1 || x.thang == 3 || x.thang == 5 || x.thang == 7 || x.thang == 8 || x.thang == 10 || x.thang == 12) && (x.ngay < 0 || x.ngay > 31))
			{
				kt = 0;
			}
			if ((x.thang == 4 || x.thang == 6 || x.thang == 9 || x.thang == 11) && (x.ngay < 0 || x.ngay > 30))
			{
				kt = 0;
			}
		}

		if (kt == 0)
		{
			cout << "\nKhong hop le . Xin vui long nhap lai!";
		}
	} while (kt == 0);
	return is;
}