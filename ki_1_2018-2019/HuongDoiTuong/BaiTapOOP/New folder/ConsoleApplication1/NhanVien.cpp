#include "stdafx.h"
#include "NhanVien.h"
#include"Date.h"
#include<stdio.h>
#include<conio.h>
#include<iomanip>
NhanVien::NhanVien()
{
}

NhanVien::~NhanVien()
{
}

NhanVien::NhanVien(const NhanVien & nv)
{
	this->id = nv.id;
	this->name = nv.name;
	this->date = nv.date;
	this->gioitinh = nv.gioitinh;
	this->salary = nv.salary;
}

void NhanVien::setId(string ID)
{
	this->id = ID;
}

void NhanVien::setName(string Name)
{
	this->name = Name;
}

void NhanVien::setDate(Date D)
{
	this->date = D;
}

void NhanVien::setSalary(double Salary)
{
	this->salary = Salary;
}

void NhanVien::setGioiTinh(bool Gioitinh)
{
	this->gioitinh = Gioitinh;
}

float NhanVien::getLuong()
{
	return this->salary;
}

string NhanVien::getName()
{
	return this->name;
}

string NhanVien::getId()
{
	return this->id;
}

void NhanVien::operator=(const NhanVien nv)
{
	id = nv.id;
	name = nv.name;
	date = nv.date;
	salary = nv.salary;
	gioitinh = nv.gioitinh;
}



istream & operator >> (istream & is, NhanVien & nv)
{
	int gt;
	cin.ignore();
	cout << "\nNhap ten nhan vien : ";
	getline(is, nv.name);
	cout << "\nNhap id nhan vien : ";
	getline(is, nv.id);
	do {
		cout << "\nNhap gioi tinh . Nam nhap true (1), nu nhap false (0): ";
		is >> gt;
	} while (gt != 0 && gt != 1);
	cin.ignore();
	nv.gioitinh = gt;
	cout << "\nNhap ngay vao lam viec : ";
	is >> nv.date;
	cout << "\nNhap luong nhan vien : ";
	is >> nv.salary;
	return is;
}

ostream & operator << (ostream & out, const NhanVien & nv)
{
	cout << setw(10) << nv.id << setw(25) << nv.name << setw(15) << nv.gioitinh << setw(20) << nv.salary<< setw(11) << nv.date;
	return out;
}