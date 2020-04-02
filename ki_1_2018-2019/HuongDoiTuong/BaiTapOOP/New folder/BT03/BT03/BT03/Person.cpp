#include "Person.h"



Person::Person()
{
}

Person::Person(string ten, int tuoi, string diachi, bool gioitinh)
	:ten(ten), tuoi(tuoi), diachi(diachi), gioitinh(gioitinh)
{
}


Person::~Person()
{
}

void Person::Nhap()
{
	cout << "\t" << "*Moi Nhap Ten: ";
	//cin.ignore();
	getline(std::cin, this->ten);
	cout << "\t" << "*Moi Nhap Tuoi: ";
	cin >> this->tuoi;
	cout << "\t" << "*Moi Nhap Dia chi: ";
	cin.ignore();
	getline(std::cin, this->diachi);
	cout << "\t" << "*Moi Nhap Gioi Tinh: ";
	cin >> this->gioitinh;
	//cout << endl;
}

void Person::Xuat()
{
	cout << "Ten: " << this->ten << endl;
	cout << "Tuoi: " << this->tuoi << endl;
	cout << "Dia Chi: " << this->diachi << endl;
	if (this->gioitinh == 1)
		cout << "Gioi tinh: Nam" << endl;
	else cout << "Gioi tinh: Nu" << endl;
}

string Person::getten()
{
	return this->ten;
}

int Person::gettuoi()
{
	return this->tuoi;
}

string Person::getdiachi()
{
	return this->diachi;
}

bool Person::getgioitinh()
{
	return this->gioitinh;
}
