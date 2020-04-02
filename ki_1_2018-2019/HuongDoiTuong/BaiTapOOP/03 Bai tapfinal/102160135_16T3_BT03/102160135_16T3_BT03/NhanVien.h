#pragma once
#include "Date.h"
using namespace std;
class NhanVien
{
protected:
	string masonhanvien, hoten;
	//double luong;
	bool gioitinh;
	Date ngayvaolam;
public:
	void operator =(const NhanVien);
	void setMaso(string);
	void setTen(string);
	void setDate(Date);
	//void setLuong(double);
	void setGioitinh(bool);
	//double getLuong();
	string getTen();
	string getMaso();
	bool getGioitinh();
	Date getDate();
	NhanVien(string = "masonhanvien", string = "abc", bool = 0, Date = Date(20, 11, 2018));//, double = 123
	virtual void Nhap();
	virtual void Xuat();
	//virtual double Luong() = 0;
	friend ostream &operator<<(ostream &, const NhanVien &);
	friend istream &operator>>(istream &, NhanVien &);
	~NhanVien();
};

