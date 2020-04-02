#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Person.h"
class Lecturer :
	public Person
{
private:
	string malecturer;
	string capbac;

public:
	Lecturer();
	Lecturer(string, string);
	~Lecturer();
	void Nhap();
	void Xuat();
	string datchuthuong(string);
	string datmalecturer(string);
	string getmalecturer();
	string getcapbac();
};

