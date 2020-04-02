#include "NODE.h"
#include <string.h>
using namespace std;
#pragma once
class QLNV
{
public:
	NODE *head;
	NODE *tail; //vong k co dau cuoi
	int n;
	string TQL;
public:
	QLNV();
	~QLNV();
	//tao danh sach
	//void CreateList(QLNV&);
	//tao node
//	static int n;
	//void operator =(const QLNV nv);
	NODE * CreateNode(NhanVien);
	void Init();
	bool IsEmpty(QLNV&);
	void Addhead(QLNV&, NhanVien);
	void Addtail(QLNV&, NhanVien);
	void Add(QLNV&, NhanVien);
	void Nhap(QLNV&);
	void Xuat(QLNV&);
	void Deletehead(QLNV&);
	void Deletetail(QLNV&);
	void Delete(QLNV&);
	void Search(NhanVien &, string);
	void Update(QLNV &);
	//NODE * mid(QLNV l);
	//void shellsort(bool(*)(string, string));
	//void Sapxep();
	friend ostream &operator<<(ostream &, const QLNV &);
	friend istream &operator>>(istream &, QLNV &);
};

