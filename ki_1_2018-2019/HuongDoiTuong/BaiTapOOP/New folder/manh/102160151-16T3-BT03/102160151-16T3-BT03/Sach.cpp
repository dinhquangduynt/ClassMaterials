#include "Sach.h"



Sach::Sach()
{
}


Sach::~Sach()
{
}

Sach::Sach(const Sach &p)
{
	this->loaisach = p.loaisach;
}
void Sach::Nhap()
{
	CongTrinhKhoaHoc::Nhap();
	cout << "\nNhap loai sach: ";
	getline(cin, this->loaisach);
}
void Sach::Xuat()
{
	CongTrinhKhoaHoc::Xuat();
}