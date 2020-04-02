#include "NVBC.h"
#include<iomanip>



NVBC::NVBC()
{
}

NVBC::NVBC(string id, string name, Date date, bool gt, double hsl)
{
	this->id = id;
	this->name = name;
	this->date = date;
	this->gioitinh = gt;
	this->hsl = hsl;
}


NVBC::~NVBC()
{
}

void NVBC::Nhap()
{
	NhanVien::Nhap();
	do {
		cout << "\nNhap he so luong : ";
		cin >> this->hsl;
		if (hsl > 10 || hsl < 2.34)
			cout << "\nNhap lai !";
	} while (hsl > 10 || hsl < 2.4);
}

void NVBC::Xuat()
{
	NhanVien::Xuat();
}

double NVBC::Luong()
{
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);
	int Thang = ltm.tm_mon + 1;
	int Nam = ltm.tm_year + 1900;
	int Ngay = ltm.tm_mday;

	int NgayVaoLam = this->date.getNgay();
	int ThangVaoLam = this->date.getThang();
	int NamVaoLam = this->date.getNam();
	if (ThangVaoLam <= Thang)
	{
		if (ThangVaoLam < Thang) {
			ThamNienLV += Nam - NamVaoLam;
			ThamNienLV += (double)(Thang - ThangVaoLam) / 12;
		}

		if (ThangVaoLam == Thang) {
			if (NgayVaoLam <= Ngay) {
				ThamNienLV += Nam - NamVaoLam;
				ThamNienLV += (double)(Thang - ThangVaoLam) / 12;
			}
			else {
				ThamNienLV += Nam - NamVaoLam;
				ThamNienLV += (Thang - 1 - ThangVaoLam) / 12;
			}
		}
	}
	else {
		if (NgayVaoLam <= Ngay)
		{
			ThamNienLV += Nam - 1 - NamVaoLam;
			ThamNienLV += (double)(Thang - ThangVaoLam + 12) / 12;
		}
		else {
			ThamNienLV += Nam - 1 - NamVaoLam;
			ThamNienLV += (double)(Thang - ThangVaoLam + 12 - 1) / 12;
		}
	}
	double hspc;
	if (this->ThamNienLV < 5)
		hspc = 0;
	else
		hspc = this->ThamNienLV / 100;

	return this->hsl * 1390000 * (1 + hspc);
}