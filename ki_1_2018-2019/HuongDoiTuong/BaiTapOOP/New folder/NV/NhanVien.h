#pragma once
#include "Date.h"
using namespace std;
class NhanVien
{
public:
	string masonhanvien,hoten;
	double luong;
	bool gioitinh;
	Date ngayvaolam;

public:
	/*void Nhap();
	void Xuat();*/	
	//NhanVien(string masonhanvien= "12345678", string hoten="abc", bool gioitinh=0, double luong =123, Date ngayvaolam = 12/8/2018);
	void ShowNv();
	friend ostream &operator<<(ostream &, const NhanVien &);
	friend istream &operator>>(istream &, NhanVien &);
	~NhanVien();
};

