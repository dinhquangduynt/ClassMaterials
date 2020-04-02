#include "NhanVien.h"
#include"Date.h"
#include<iomanip>
NhanVien::NhanVien()
{
}

NhanVien::~NhanVien()
{
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

void NhanVien::setGioiTinh(bool Gioitinh)
{
	this->gioitinh = Gioitinh;
}

string NhanVien::getName()
{
	return this->name;
}

string NhanVien::getId()
{
	return this->id;
}

Date NhanVien::getDate()
{
	return this->date;
}

bool NhanVien::getGioiTinh()
{
	return this->gioitinh;
}



void NhanVien::Nhap()
{
	int gt;
	int length;
	do {
		cout << "\nNhap id nhan vien : ";
		getline(cin, this->id);
		length = this->id.length();
		if (length != 8)
			cout << "\nNhap lai ! ";
	} while (length != 8);
	cout << "\nNhap ten nhan vien : ";
	getline(cin, this->name);
	do {
		cout << "\nNhap gioi tinh . Nam nhap true (1), nu nhap false (0): ";
		cin >> gt;
	} while (gt != 0 && gt != 1);
	cin.ignore();
	this->gioitinh = gt;
	cout << "\nNhap ngay vao lam viec : ";
	cin >> this->date;
}

void NhanVien::Xuat()
{
	this->salary = this->Luong();
	string gt;
	if (this->gioitinh == 1)
		gt = "Nam";
	if (this->gioitinh == 0)
		gt = "Nu";
	cout << setw(10) << this->id << setw(25) << this->name << setw(15) << gt << setw(15) << this->date << setw(20) << this->salary;
}