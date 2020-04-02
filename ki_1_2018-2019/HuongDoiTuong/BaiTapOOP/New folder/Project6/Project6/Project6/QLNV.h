#pragma once
#include<string>
#include"NhanVien.h"
#include"NVBC.h"
#include"NVHD.h"
#include"Queue.h"

class QLNV
{
private:
	string TenQL;
	Queue q;
	int n;
public:
	QLNV();
	~QLNV();
	// QLNV(const QLNV &ql);
	void Nhap();
	void Xuat();
	void Them();
	void Xoa();
	void TimKiem();
	void CapNhat();
};