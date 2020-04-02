#pragma once
#include "NhanVien.h"
#include"Date.h"
#include <ctime>
class NVBC :
	public NhanVien
{
private:
	double hsl, thamnien;
public:
	double getHSL();
	double getThamnien();
	void setHSL(double);
	void setThamnien(double);
	NVBC(const NVBC&);
	virtual void Nhap();
	virtual void Xuat();
	double Luong();
	NVBC(string ="11111111", string ="duy",bool=0, Date=Date(11,12,2018),double =2.34);
	~NVBC();
};

