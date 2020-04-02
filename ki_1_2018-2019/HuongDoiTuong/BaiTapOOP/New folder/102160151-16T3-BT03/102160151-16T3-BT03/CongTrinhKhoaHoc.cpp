#include "CongTrinhKhoaHoc.h"
#include<iomanip>



CongTrinhKhoaHoc::CongTrinhKhoaHoc()
{
}


CongTrinhKhoaHoc::~CongTrinhKhoaHoc()
{
}
CongTrinhKhoaHoc::CongTrinhKhoaHoc(const CongTrinhKhoaHoc &p)
{
	this->MCT = p.MCT;
	this->NXB = p.NXB;
	this->KVXB = p.KVXB;
}
void CongTrinhKhoaHoc::setMCT(string MCT)
{
	this->MCT=MCT;
}
string CongTrinhKhoaHoc::getMCT()
{
	return this->MCT;
}
void CongTrinhKhoaHoc::setNXB(int NXB)
{
	this->NXB = NXB;
}
int CongTrinhKhoaHoc::getNXB()
{
	return this->NXB;
}
void CongTrinhKhoaHoc::setKVXB(bool KVXB)
{
	this->KVXB = KVXB;
}
void CongTrinhKhoaHoc::Nhap()
{
	cin.ignore();
	cout << "\nNhap ma cong trinh: ";
	getline(cin,this-> MCT);
	do {
		cout << "\nNhap nam xuat ban: ";
		cin >> this->NXB;
	} while (this->NXB < 1900);
	this->NXB = NXB;
	do {
		cout << "\nNhap noi xuat ban .xuat ban quoc te nhap 1 ,xuat ban trong nuoc nhap 0 : ";
		cin >> this->KVXB;
	} while (this->KVXB != 0 && this->KVXB != 1);
	cin.ignore();
	this->KVXB = KVXB;
}
void CongTrinhKhoaHoc::Xuat()
{
	//cout << "Ma cong trinh: " << this->MCT << "nam xuat ban:" << this->NXB << "khu vuc xuat ban:" << this->KVXB << endl;
	cout << setw(10) << this->MCT << setw(25) << this->NXB << setw(15) << this->KVXB ;
}