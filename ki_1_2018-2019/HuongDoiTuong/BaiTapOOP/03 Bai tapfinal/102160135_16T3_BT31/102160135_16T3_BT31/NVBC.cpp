#include "NVBC.h"



double NVBC::getHSL()
{
	return hsl;
}


double NVBC::getThamnien()
{
	return thamnien;
}

void NVBC::setHSL(double HSL)
{
	hsl = HSL;
}

void NVBC::setThamnien(double tn)
{
	thamnien = tn;
}

NVBC::NVBC(const NVBC &nvbc)
{
	hsl = nvbc.hsl;
	thamnien = nvbc.thamnien;
}

NVBC::NVBC(string ms, string ht, bool gt, Date d, double hs)
{
	masonhanvien = ms;
	hoten = ht;
	gioitinh = gt;
	ngayvaolam = d;
	hsl = hs;
}

void NVBC::Nhap()
{
	NhanVien::Nhap();
	do {
		cout << "\nNhap he so luong : ";
		cin >> hsl;
		if (hsl > 10 || hsl < 2.34)
			cout << "\nVui long nhap lai!";
	} while (hsl > 10 || hsl < 2.34);
}

void NVBC::Xuat()
{
	NhanVien::Xuat();
	cout << "\nHe so luong: " << hsl;
	cout << "\nLuong: " << Luong();
	cout << endl;
}

double NVBC::Luong()
{
	double hspc;
	
	time_t baygio = time(0);
	struct tm ltm;
	localtime_s(&ltm, &baygio);
	int thang = ltm.tm_mon + 1;
	int nam = ltm.tm_year + 1900;
	int ngay = ltm.tm_mday;

	int ngayvao = ngayvaolam.getNgay();
	int thangvaolam = ngayvaolam.getThang();
	int namvaolam = ngayvaolam.getNam();
	thamnien = nam - namvaolam;
	if (thamnien > 5) {
		
		hspc = thamnien / 100;
	}
	else if (thamnien > 5 || (thamnien == 5 && thang > thangvaolam ) || (thamnien == 5 && thang == thangvaolam && ngay >= ngayvao))
	{
		hspc = thamnien / 100;
	}
	else hspc = 0;
	
	return (hsl *1390000)*(1+hspc);
}






NVBC::~NVBC()
{
}
