#include "ListCTKH.h"
#include"CongTrinhKhoaHoc.h"
#include<iomanip>
#include<string>


ListCTKH::ListCTKH()
{
}


ListCTKH::~ListCTKH()
{
}

ListCTKH::ListCTKH(const ListCTKH &p)
{
	this->tenTG = p.tenTG;
	this->soCTKH = p.soCTKH;
}
int ListCTKH::getN()
{
	return this->soCTKH;
}
void ListCTKH::Nhap()
{
	cout << "\nNhap ten tac gia : ";
	getline(cin, this->tenTG);
}
void ListCTKH::Xuat()
{
	CongTrinhKhoaHoc *nv = NULL;
	cout << "\nTen tac gia  : " << this->tenTG << " - So luong CTKH : " << this->soCTKH << endl << "Danh sach cong trinh khoa hoc " << endl;
	for (int i = 0; i < soCTKH; i++) {
		if (!q.isEmpty())
		{
			q.Pop(nv);
			nv->Xuat();
			q.Push(nv);
			cout << endl;
		}
	}
}
void ListCTKH::Them()
{
	int lc, kt = 0;
	CongTrinhKhoaHoc *nv = NULL;
	CongTrinhKhoaHoc *nvkt = NULL;
	string MCT;
	cout << "\nBan muon them vao sach hay bai bao : \n 1 . sach \n 2 . baibao";
	do {
		cout << "\nNhap vao lua chon . ";
		cin >> lc;
		if (lc != 1 && lc != 2)
			cout << "\nNhap lai !";
	} while (lc != 1 && lc != 2);
	

	if (lc == 1)
	{
		nv = new Sach();
		nv->Nhap();
		MCT = nv->getMCT();
		for (int i = 0; i < soCTKH; i++)
		{
			q.Pop(nvkt);
			if (nvkt->getMCT() == MCT)
			{
				kt = 1;
				//break;
			}
			q.Push(nvkt);
		}
		if (kt == 1)
			cout << "\nDa ton tai MCT tren trong danh sach . ";
		else
		{
			q.Push(nv);
			soCTKH++;
		}
	}
	if (lc == 2)
	{
		nv = new BaiBao();
		nv->Nhap();
		MCT = nv->getMCT();
		for (int i = 0; i < soCTKH; i++)
		{
			q.Pop(nvkt);
			if (nvkt->getMCT() == MCT)
			{
				kt = 1;
				//break;
			}
			q.Push(nvkt);
		}
		if (kt == 1)
			cout << "\nDa ton tai MCT tren trong danh sach . ";
		else
		{
			q.Push(nv);
			soCTKH++;
		}
	}
}
void ListCTKH::Xoa()
{
	CongTrinhKhoaHoc *nv = NULL;
	int kt = 0;
	string MCT;
	cin.ignore();
	cout << "\nNhap vao id ban muon xoa . ";
	getline(cin, MCT);
	for (int i = 0; i < soCTKH; i++)
	{
		q.Pop(nv);
		if (nv->getMCT() == MCT)
		{
			kt = 1;
			continue;
		}

		q.Push(nv);
	}
	if (kt == 1)
		soCTKH--;
	if (kt == 0)
		cout << "\nKhong ton tai MCT ban muon xoa . ";
}
void ListCTKH::CapNhat()
{
	int kt = 0;
	CongTrinhKhoaHoc *nv = NULL;
	string MCT;
	cout << "\nNhap id ban muon cap nhat . ";
	getline(cin, MCT);
	for (int i = 0; i < soCTKH; i++)
	{
		q.Pop(nv);
		if (nv->getMCT() == MCT)
		{

		}
	}
}
void ListCTKH::TimKiem()
{
	int kt = 0;
	string MCT;
	CongTrinhKhoaHoc *nv = NULL;
	cin.ignore();
	cout << "\nNhap vao id ban muon tim kiem . ";
	getline(cin, MCT);
	for (int i = 0; i < soCTKH; i++)
	{
		q.Pop(nv);
		if (nv->getMCT() == MCT)
		{
			kt = 1;
			cout << "\nma cong trinh ban muon tim kiem la : " << endl;
			cout << setw(10) << "MCT" << setw(25) << "Nam XB" << setw(15) << "KVXB" <<  endl;
			nv->Xuat();
		}
		q.Push(nv);
	}
	if (kt == 0)
		cout << "\nKhong ton taicong nao co ma id nhu tren trong danh sach";
}
void ListCTKH::operator=(const ListCTKH p)
{
	tenTG = p.tenTG;
	soCTKH = p.soCTKH;
}
/*istream & operator >> (istream & i, ListCTKH &ct)
{
	string tenTG;
	int soCTKH;
	cout << "\nNhap ten tac gia: ";
	getline(i, ct.tenTG);
	cout << "\nNhap soCTKH: ";
	i >> soCTKH;
	ct.soCTKH = soCTKH;
	return i;
}
ostream & operator <<(ostream &o, ListCTKH &ct)
{
	o << ct.tenTG << ct.soCTKH;
	return o;
}*/
