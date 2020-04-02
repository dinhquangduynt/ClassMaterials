#include "Lecturer.h"



Lecturer::Lecturer()
{
}

Lecturer::Lecturer(string malecturer, string capbac)
	:malecturer(malecturer),capbac(capbac)
{
}


Lecturer::~Lecturer()
{
}

void Lecturer::Nhap()
{
	Person::Nhap();
	this->malecturer = datmalecturer(this->ten);
	cin.ignore();
	cout <<"\t"<< "*Nhap Cap Bac: ";
	getline(std::cin, this->capbac);
}

void Lecturer::Xuat()
{
	Person::Xuat();
	cout << "Ma Lecturer: " << this->malecturer << endl;
	cout << "Cap Bac: " << this->capbac << endl;
}

string Lecturer::datchuthuong(string ten)
{
	for (int i = 0; i < ten.length(); i++)
	{
		if (ten[i] >= 'A' && ten[i] <= 'Z')
			ten[i] = char(ten[i] + 32);
	}
	return ten;
}

string Lecturer::datmalecturer(string ten)
{
	ten = datchuthuong(ten);
	string malecturer = "102";
	malecturer = malecturer + ten[0];
	string tam = "";
	for (int i = 0; i < ten.length(); i++)
	{
		if (ten[i] == ' ') tam = "";
		else tam = tam + ten[i];
		if (ten[i] == ' ' && ten[i + 1] != ' ') malecturer = malecturer + ten[i + 1];
	}
	tam.erase(tam.begin() + 0); // xoa ky tu bi du 
	malecturer = malecturer + tam;
	return malecturer;
}

string Lecturer::getmalecturer()
{
	return this->malecturer;
}

string Lecturer::getcapbac()
{
	return this->capbac;
}

