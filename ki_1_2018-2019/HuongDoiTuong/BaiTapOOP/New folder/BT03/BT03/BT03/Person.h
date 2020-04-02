#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
	string ten;
	int tuoi;
	string diachi;
	bool gioitinh;
public:
	Person();
	Person(string, int, string, bool);
	~Person();
	void Nhap();
	void Xuat();
	string getten();
	int gettuoi();
	string getdiachi();
	bool getgioitinh();
};

