#pragma once
#include "Date.h"
using namespace std;
class NhanVien
{
public:
	string masonhanvien, hoten;
	double luong;
	bool gioitinh;
	Date ngayvaolam;

public:
	NhanVien(string masonhanvien = "masonhanvien", string hoten = "abc", bool gioitinh = 0,double luong = 123, Date ngayvaolam=12/2/2018);
	void Nhap();
	void Xuat();	
	void ShowNv();
	friend ostream &operator<<(ostream &, const NhanVien &);
	friend istream &operator>>(istream &, NhanVien &);
	~NhanVien();
};

