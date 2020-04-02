
#pragma once
#include"NhanVien.h"
class NVHD :public NhanVien
{
private:
	double LuongCN;
public:
	NVHD();
	~NVHD();
	NVHD(string id, string name, Date date, bool gt, double LuongCN);
	void Nhap();
	void Xuat();
	double Luong();
};