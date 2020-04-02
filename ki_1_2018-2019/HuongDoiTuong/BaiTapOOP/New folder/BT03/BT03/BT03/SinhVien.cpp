#include "SinhVien.h"
#include "LopSinhHoat.h"


SinhVien::SinhVien() : Person()
{
}

//SinhVien::SinhVien(string mssv, LopSinhHoat lop, double diemtb)
//	: mssv(mssv), lop(lop), diemtb(diemtb)
//{
//}


SinhVien::~SinhVien()
{
}

void SinhVien::Nhap()
{
	cin.ignore();
	cout << endl;
	Person::Nhap();
	cin.ignore();
	while (true)
	{
		cout << "\t" << "*Moi Nhap MSSV: ";
		getline(std::cin, this->mssv);
		if (ktmssv(mssv) == true) break;
		else cout << "Khong dung dinh dang!" << endl;
	}

	while (true)
	{
		cout << "\t" << "*Moi Nhap Diem TB: ";
		cin >> this->diemtb;
		if (ktdiemtb(diemtb) == true) break;
		else cout << "Khong dung dinh dang!" << endl;

	}
	//cin.ignore();
}

void SinhVien::Xuat()
{
	Person::Xuat();
	cout << "MSSV: " << this->mssv << endl;
	cout << "Diem TB: " << this->diemtb << endl ;
}



bool SinhVien::ktmssv(string mssv)
{
	if (mssv.length() != 10) return false;
	if (mssv[0] == '0') return false;
	for (int i = 0; i < mssv.length(); i++)
		if (mssv[i] > '9' || mssv[i] < '0') return false;
	return true;
}

bool SinhVien::ktdiemtb(double diemtb)
{
	if (diemtb >= 0 && diemtb <= 4)
		return true;
	else 
	return false;
}

string SinhVien::getmssv()
{
	return this->mssv;
}

double SinhVien::getdiemtb()
{
	return this->diemtb;
}
