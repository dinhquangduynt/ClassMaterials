#include<iostream>
using namespace std;
#pragma once

class MyString
{
private:
	int n;
	char* data;
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);

	MyString operator+(const MyString&);
	MyString operator&(const MyString&);
	MyString operator=(const MyString&);

	bool operator==(const MyString&);
	bool operator!=(const MyString&);

	bool operator>(const MyString&);
	bool operator>=(const MyString&);
	bool operator<(const MyString&);
	bool operator<=(const MyString&);


	char operator [] (int);
	void Xuatkitu(MyString&);
	friend ostream& operator<<(ostream&, const MyString&);
	friend istream& operator>>(istream&, const MyString&);
	void Ghivaoxau(MyString&);
	~MyString();
};

