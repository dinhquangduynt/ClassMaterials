#pragma once
#include<iostream>
#include"CongTrinhKhoaHoc.h"
using namespace std;
class BaiBao: public CongTrinhKhoaHoc
{
private:
	string TCT;
	int STG;
public:
	BaiBao();
	~BaiBao();
	BaiBao(const BaiBao &p);
	void setTCT(string TCT);
	string getTCT();
	void setSTG(int STG);
	int getSTG();
	void Nhap();
	void Xuat();
};

