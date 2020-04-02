#pragma once
#include "NhanVien.h"
class NVHD :
	public NhanVien
{
private:
	double luongcong;
public:
	void Nhap();
	void Xuat();
	//double Luong();

	NVHD();
	~NVHD();
};

