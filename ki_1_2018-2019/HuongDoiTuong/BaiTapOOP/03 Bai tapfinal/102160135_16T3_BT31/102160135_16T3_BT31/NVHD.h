#pragma once
#include "NhanVien.h"
class NVHD :
	public NhanVien
{
private:
	double luongcong;
public:
	virtual void Nhap();
	virtual void Xuat();
	//double Luong();
	
	NVHD();
	~NVHD();
};

