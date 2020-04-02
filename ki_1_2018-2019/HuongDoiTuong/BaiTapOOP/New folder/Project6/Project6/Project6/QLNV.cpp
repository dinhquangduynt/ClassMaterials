#include "QLNV.h"
#include "NhanVien.h"
#include<iomanip>
#include<string>
QLNV::QLNV()
{
	this->n = 2;
	NhanVien *nv = new NVBC("NVBC0001", "1111", Date(), true, 3.3);
	q.Push(nv);
	NhanVien *nv2 = new NVHD("NVHD0002", "2222", Date(), true, 200);
	q.Push(nv2);
	//NhanVien *nv3;
}

QLNV::~QLNV()
{

}

/*QLNV::QLNV(const QLNV & ql)
{
	this->ds = ql.ds;
	this->n = ql.n;
	this->TenQL = ql.TenQL;
}*/

void QLNV::Nhap()
{
	cout << "\nNhap ten quan li : ";
	getline(cin, this->TenQL);
}

void QLNV::Xuat()
{
	NhanVien *nv = NULL;
	cout << "\nTen quan li  : " << this->TenQL << " - So luong nhan vien : " << this->n << endl << "Danh sach nhan vien " << endl;
	for (int i = 0; i < n; i++) {
		if (!q.isEmpty())
		{
			q.Pop(nv);
			nv->Xuat();
			q.Push(nv);
			cout << endl;
		}
	}
	//q.Push(nv);
	//q.Pop(nv);
	//nv->Xuat();
}

void QLNV::Them()
{
	int lc, kt = 0;
	NhanVien *nv = NULL;
	NhanVien *nvkt = NULL;
	string id;
	cout << "\nBan muon them vao nhan vien loai gì : \n 1 . NVHD \n 2 NVBC";
	do {
		cout << "\nNhap vao lua chon . ";
		cin >> lc;
		if (lc != 1 && lc != 2)
			cout << "\nNhap lai !";
	} while (lc != 1 && lc != 2);
	

	if (lc == 1)
	{
		nv = new NVHD();
		nv->Nhap();
		id = nv->getId();
		for (int i = 0; i < n; i++)
		{
			q.Pop(nvkt);
			if (nvkt->getId() == id)
			{
				kt = 1;
				//break;
			}
			q.Push(nvkt);
		}
		if (kt == 1)
			cout << "\nDa ton tai id tren trong danh sach . ";
		else
		{
			q.Push(nv);
			n++;
		}
	}
	if (lc == 2)
	{
		nv = new NVBC();
		nv->Nhap();
		id = nv->getId();
		for (int i = 0; i < n; i++)
		{
			q.Pop(nvkt);
			if (nvkt->getId() == id)
			{
				kt = 1;
				//break;
			}
			q.Push(nvkt);
		}
		if (kt == 1)
			cout << "\nDa ton tai id tren trong danh sach . ";
		else
		{
			q.Push(nv);
			n++;
		}
	}
}



void QLNV::Xoa()
{
	NhanVien *nv = NULL;
	int kt = 0;
	string id;
	cin.ignore();
	cout << "\nNhap vao id ban muon xoa . ";
	getline(cin, id);
	for (int i = 0; i < n; i++)
	{
		q.Pop(nv);
		if (nv->getId() == id)
		{
			kt = 1;
			continue;
		}
		
		q.Push(nv);
	}
	if (kt == 1)
		n--;
	if (kt == 0)
		cout << "\nKhong ton tai id ban muon xoa . ";
}


void QLNV::TimKiem()
{
	int kt = 0;
	string id;
	NhanVien *nv = NULL;
	cin.ignore();
	cout << "\nNhap vao id ban muon tim kiem . ";
	getline(cin, id);
	for (int i = 0; i < n; i++)
	{
		q.Pop(nv);
		if (nv->getId() == id)
		{
			kt = 1;
			cout << "\nNhan vien ban muon tim kiem la : " << endl;
			cout << setw(10) << "id" << setw(25) << "Name" << setw(15) << "Gioi Tinh" << setw(15) << "Ngay Vl" << setw(15) << "Luong" << endl;
			nv->Xuat();
		}
		q.Push(nv);
	}
	if (kt == 0)
		cout << "\nKhong ton tai nhan vien nao co ma id nhu tren trong danh sach";
}

void QLNV::CapNhat()
{
	int kt = 0;
	NhanVien *nv = NULL;
	string id;
	cout << "\nNhap id ban muon cap nhat . ";
	getline(cin, id);
	for (int i = 0; i < n; i++)
	{
		q.Pop(nv);
		if (nv->getId() == id)
		{

		}
	}
}
