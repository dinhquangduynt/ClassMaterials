#pragma once
#include<string>
#include"iostream"
using namespace std;
class CongTrinhKhoaHoc
{
protected:
	string MCT;
	int NXB;
	bool KVXB;
public:
	CongTrinhKhoaHoc();
	~CongTrinhKhoaHoc();
	CongTrinhKhoaHoc(const CongTrinhKhoaHoc &p);
	void setMCT(string MCT);
	string getMCT();
	void setNXB(int NXB);
	int getNXB();
	void setKVXB(bool KVXB);
	//void nhap();
	//void xuat();
	virtual void  Nhap();
	virtual void  Xuat();
};

