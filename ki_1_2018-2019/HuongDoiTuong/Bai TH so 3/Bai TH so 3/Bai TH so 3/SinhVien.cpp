#include "SinhVien.h"



SinhVien::SinhVien()
{
}


SinhVien::~SinhVien()
{
}

istream & operator>>(istream &is, SinhVien &sv)
{
	
	cout << "MSSV: ";
	is >> sv.MSSV;
	cout << "Ho ten sinh vien: ";
	is.ignore();
	getline(is, sv.HoTen);
	cout << "Nam Sinh: ";
	is >> sv.NamSinh;
	return is;
}

ostream & operator<<(ostream &os, SinhVien &sv)
{
	os << "MSSV: " << sv.MSSV << endl;
	os << "Ho Ten: " << sv.HoTen << endl;
	os << "Nam Sinh: " << sv.NamSinh << endl;
	return os;
}
