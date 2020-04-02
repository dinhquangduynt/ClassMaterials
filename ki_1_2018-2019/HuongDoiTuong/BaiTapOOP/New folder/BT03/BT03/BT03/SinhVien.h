#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Person.h"
//#include "LopSinhHoat.h"
class LopSinhHoat;
class SinhVien :
	public Person
{
private:
	string mssv;
	LopSinhHoat *lop; 
	double diemtb;
public:
	SinhVien();
	//SinhVien(string, LopSinhHoat, double);
	~SinhVien();
	void Nhap();
	void Xuat();
	bool ktmssv(string);
	bool ktdiemtb(double);
	string getmssv();
	double getdiemtb();
};

