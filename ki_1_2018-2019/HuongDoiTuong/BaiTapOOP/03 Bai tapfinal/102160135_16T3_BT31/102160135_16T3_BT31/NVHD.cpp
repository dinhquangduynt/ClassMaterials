#include "NVHD.h"



void NVHD::Nhap()
{
	NhanVien::Nhap();
	cout << "\nNhap luong cong nhat: ";
	cin >> luongcong;
}

void NVHD::Xuat()
{
	NhanVien::Xuat();
	cout << "\nLuong cong nhat: " << luongcong;
	cout << endl;
}

NVHD::NVHD()
{
	
}


NVHD::~NVHD()
{
}
