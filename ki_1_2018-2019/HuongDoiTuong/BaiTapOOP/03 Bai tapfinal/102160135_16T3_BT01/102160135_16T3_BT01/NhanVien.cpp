#include "NhanVien.h"
NhanVien::NhanVien(string msnv, string hoten, bool gioitinh, double luong, Date ngayvaolam)
{
	this->masonhanvien = msnv;
	this->hoten = hoten;
	this->gioitinh = gioitinh;	
	this->luong = luong;
	this->ngayvaolam = ngayvaolam;
}

void NhanVien::Nhap()
{
	do
	{
		fflush(stdin);
		cout << "\nNhap ma so nhan vien: ";
		getline(cin, masonhanvien);
		if (masonhanvien.length() > 8)
			cout << "\nma so nhan vien khong hop le!";
	} while (masonhanvien.length() > 8);

	fflush(stdin);
	cout << "\nNhap ten nhan vien: ";
	getline(cin, hoten);	
	fflush(stdin);
	do {
		cout << "\nNhap gioi tinh (Nhap 1 neu la nam, 0 neu la nu): ";
		cin >> gioitinh;
		if (gioitinh != 0 && gioitinh != 1)
			cout << "\ngoi tinh khong hop le!";
		
	} while (gioitinh != 0 && gioitinh != 1);
	cout << "\nLuong: ";
	cin >> luong; 

	cout << "\nNhap ngay vao lam: ";
	ngayvaolam.Nhapdate();
}
void NhanVien::Xuat()
{
	cout << "\nma so nhan vien: " << masonhanvien;
	cout << "\nho ten nhan vien: " << hoten;
	cout << "\n gioi tinh: " << gioitinh;
	cout << "\nluong: " << luong;
	cout << "\nNgay vao lam: ";
	ngayvaolam.Xuatdate();
}
void NhanVien::ShowNv()
{
	cout << "\nma so nhan vien: " << this->masonhanvien;
	cout << "\nho ten nhan vien: " << this->hoten;
	cout << "\n gioi tinh: " << this->gioitinh;
	cout << "\nluong: " << this->luong;
	cout << "\nNgay vao lam: " << this->ngayvaolam;

}


//da nang hoa ham xuat
ostream& operator<<(ostream &o, const NhanVien &nv)
{
	o << "\nMa so nhan vien: " << nv.masonhanvien;
	o << "\nHo ten nhan vien: " << nv.hoten;
	/*if (nv.gioitinh == 0)
		o << "\nGioi tinh: " << "Nam";
	else if (nv.gioitinh==1)
	{
		o << "\nGioi tinh: " << "Nu";
	}*/
	o << "\nGioi tinh: " << nv.gioitinh;
	o << "\nLuong: " << nv.luong;
	o << "\nNgay vao lam: " << nv.ngayvaolam;


	return o;
}

//da nang hoa ham nhap

istream& operator>>(istream &i, NhanVien &nv)
{
	cin.ignore();
	do
	{
		cout << "\nNhap ma so nhan vien: ";
		getline(i, nv.masonhanvien);
		if (nv.masonhanvien.length() != 8)
			cout << "\nMa so nhan vien khong hop le!";
	} while (nv.masonhanvien.length() != 8);

	do
	{
		cout << "\nNhap ten nhan vien: ";
		getline(i, nv.hoten);
		if (nv.hoten.length() == 0)
			cout << "\nTen khong hop le!";
	} while (nv.hoten.length() == 0);

	//do {
	cout << "\nNhap gioi tinh (Nhap 0 neu la nam, 1 neu la nu): ";
	i >> nv.gioitinh;
	/*if (nv.gioitinh != 0 && nv.gioitinh != 1)
	{
		cout << "\Gioi tinh khong hop le!";
	}*/
	//} while (nv.gioitinh != 0 && nv.gioitinh != 1);

	cout << "\nLuong: ";
	i >> nv.luong;

	cout << "\nNhap ngay vao lam: ";
	nv.ngayvaolam.Nhapdate();


	return i;
}
NhanVien::~NhanVien()
{
}
