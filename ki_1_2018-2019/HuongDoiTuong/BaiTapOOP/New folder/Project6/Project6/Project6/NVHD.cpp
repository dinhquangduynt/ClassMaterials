#include "NVHD.h"
#include<ctime>
#include<iomanip>

NVHD::NVHD()
{
}


NVHD::~NVHD()
{
}

NVHD::NVHD(string id, string name, Date date, bool gt, double LuongCN)
{
	this->id = id;
	this->name = name;
	this->date = date;
	this->gioitinh = gt;
	this->LuongCN = LuongCN;
}

void NVHD::Nhap()
{
	NhanVien::Nhap();
	cout << "\nNhap luong cong nhat : ";
	cin >> this->LuongCN;
}

void NVHD::Xuat()
{
	NhanVien::Xuat();
}

double NVHD::Luong()
{
	int count = 0;
	int songay;
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);
	int Thang = ltm.tm_mon + 1;
	int Nam = ltm.tm_year;
	int thu = ltm.tm_wday;
	int Ngay = ltm.tm_mday;
	int du = Ngay % 7;
	while (du > 0)
	{
		thu--;
		du--;
		if (thu < 0)
			thu = 6;
	}
	Ngay = 1;
	if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
		songay = 31;
	else if (Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11)
		songay = 30;
	else {
		if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)
			songay = 29;
		else
			songay = 28;
	}
	while (Ngay <= songay)
	{

		if (thu != 0 && thu != 6)
		{
			count++;
		}
		thu++;
		if (thu == 7)
			thu = 0;
		Ngay++;
	}
	return count * this->LuongCN;
}