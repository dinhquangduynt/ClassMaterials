#include "Date.h"
#include<iostream>
#include<string>
using namespace std;


Date::~Date()
{
}

Date::Date(int Ngay, char kt1, int Thang, char kt2, int Nam)
{
	this->kt1 = kt1;
	this->ngay = Ngay;
	this->thang = Thang;
	this->nam = Nam;
	this->kt2 = kt2;
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

int Date::getNgay()
{
	return this->ngay;
}

int Date::getThang()
{
	return this->thang;
}


int Date::getNam()
{
	return this->nam;
}

bool Date::KTNam()
{
	if ((this->getNam() % 4 == 0 && this->getNam() % 100 != 0) || this->getNam() % 400 == 0)
		return true;
	return false;
}

ostream & operator<<(ostream & out, const Date & x)
{
	out << x.ngay << x.kt1 << x.thang << x.kt2 << x.nam;
	return out;
}

istream & operator >> (istream & is, Date & x)
{
	cout << "\nVui long nhap dung dinh dang day/month/year";
	int kt;
	do {
		kt = 1;
		is >> x.ngay;
		is >> x.kt1;
		is >> x.thang;
		is >> x.kt2;
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
		if (x.kt1 != '/' || x.kt2 != '/')
			kt = 0;

		if (kt == 0)
		{
			cout << "\nKhong hop le . Xin vui long nhap lai!";
		}
	} while (kt == 0);
	return is;
}