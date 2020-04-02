#include "BaiBao.h"



BaiBao::BaiBao()
{
}


BaiBao::~BaiBao()
{
}
BaiBao::BaiBao(const BaiBao &p)
{
	this->TCT =p.TCT;
	this->STG = p.STG;
}
void BaiBao::setTCT(string TCT)
{
	this->TCT = TCT;
}
string BaiBao::getTCT()
{
	return this->TCT;
}
void BaiBao::setSTG(int STG)
{
	this->STG = STG;
}
int BaiBao::getSTG()
{
	return this->STG;
}
void BaiBao::Nhap()
{
	CongTrinhKhoaHoc::Nhap();
	cout << "\nNhap ten cong trinh: ";
	getline(cin, this->TCT);
	cout << "\nNhap so tac gia: ";
	cin >> this->STG;
}
void BaiBao::Xuat()
{
	CongTrinhKhoaHoc::Xuat();
}
