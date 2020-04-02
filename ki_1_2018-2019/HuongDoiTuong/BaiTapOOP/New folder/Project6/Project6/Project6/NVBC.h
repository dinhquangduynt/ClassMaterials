#pragma once
#include"NhanVien.h"
class NVBC :public NhanVien
{
private:
	double hsl;
	double ThamNienLV = 0.0;
public:
	NVBC();
	NVBC(string id, string name, Date date, bool gt, double hsl);
	~NVBC();
	void Nhap();
	void Xuat();
	double Luong();
};