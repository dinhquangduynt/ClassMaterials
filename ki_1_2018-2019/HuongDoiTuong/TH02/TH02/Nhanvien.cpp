#include "NhanVien.h"
NhanVien::NhanVien(string msnv, string hoten, bool gioitinh, double luong, Date ngayvaolam)
{
	this->MSNV = msnv;
	this->Name = hoten;
	this->GioiTinh = gioitinh;
	this->Luong = luong;
	this->Ngay = ngayvaolam;
}

void NhanVien::Nhap()
{
	do
	{
		fflush(stdin);
		cout << "\nNhap ma so nhan vien: ";
		getline(cin, this->MSNV);
		if (this->MSNV.length() != 8)
			cout << "\nMa so nhan vien khong hop le!";
	} while (MSNV.length() > 8);

	fflush(stdin);
	cout << "\nNhap ten nhan vien: ";
	getline(cin, Name);
	fflush(stdin);
	do {
		cout << "\nNhap gioi tinh (Nhap 1 neu la nam, 0 neu la nu): ";
		cin >> GioiTinh;
		if (GioiTinh != 0 && GioiTinh != 1)
			cout << "\Gioi tinh khong hop le!";

	} while (GioiTinh != 0 && GioiTinh != 1);
	cout << "\nLuong: ";
	cin >> Luong;

	cout << "\nNhap ngay vao lam: ";
	Ngay.Nhapdate();
}
void NhanVien::Xuat()
{
	cout << "\nma so nhan vien: " << this->MSNV;
	cout << "\nho ten nhan vien: " << this->Name;
	cout << "\n gioi tinh: " << this->GioiTinh;
	cout << "\nluong: " << this->Luong;
	cout << "\nNgay vao lam: ";
	this->Ngay.Xuatdate();
}


NhanVien::~NhanVien()
{
}
