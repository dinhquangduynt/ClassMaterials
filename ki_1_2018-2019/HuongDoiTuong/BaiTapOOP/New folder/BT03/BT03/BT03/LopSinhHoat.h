#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Lecturer.h"
//#include "SinhVien.h"
//#include "Node.h"
class Node;
class LopSinhHoat
{
private:
	string tenlopsinhhoat;
	Node *head;
	Node *tail;
	Lecturer lecturer;
	int sisosv;
public:
	LopSinhHoat();
	~LopSinhHoat();
	friend istream &operator >> (istream &i, LopSinhHoat &);
	friend ostream &operator << (ostream &o, LopSinhHoat &);
	void chendau(Node *);
	void chencuoi(Node *);
	void chenbatky(int, Node *);
	void capnhat(int);
	void xoa(int);
	void timkiem();
	Lecturer getlecturer();
	void xuatlec();
};

