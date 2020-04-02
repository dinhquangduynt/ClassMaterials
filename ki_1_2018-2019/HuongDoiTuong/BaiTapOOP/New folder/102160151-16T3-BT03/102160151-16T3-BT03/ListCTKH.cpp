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
//void ListCTKH::Nhap()
//{
	//cout << "\nNhap ten tac gia : ";
	//getline(cin, this->tenTG);
//}
void ListCTKH::Xuat()
{
	CongTrinhKhoaHoc *ct = NULL;
	cout << "\nTen tac gia  : " << this->tenTG << " - So luong CTKH : " << this->soCTKH << endl << "Danh sach cong trinh khoa hoc " << endl;
	cout << setw(10) << "MCT" << setw(25) << "Nam XB" << setw(15) << "KVXB" << setw(25) << "ten loai sach/ten CT" << setw(20) << "so tac gia" << endl;
	for (int i = 0; i < soCTKH; i++) {
		if (!q.isEmpty())
		{
			q.Pop(ct);
			ct->Xuat();
			cout << endl;
			q.Push(ct);
			
		}
	}
}
void ListCTKH::Them()
{
	int lc, kt = 0;
	CongTrinhKhoaHoc *ct = NULL;
	CongTrinhKhoaHoc *ctkt = NULL;
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
		ct = new Sach();
		ct->Nhap();
		MCT = ct->getMCT();
		for (int i = 0; i < soCTKH; i++)
		{
			q.Pop(ctkt);
			if (ctkt->getMCT() == MCT)
			{
				kt = 1;
				//break;
			}
			q.Push(ctkt);
		}
		if (kt == 1)
			cout << "\nDa ton tai MCT tren trong danh sach . ";
		else
		{
			q.Push(ct);
			soCTKH = soCTKH + 1;
		}
	}
	if (lc == 2)
	{
		ct = new BaiBao();
		ct->Nhap();
		MCT = ct->getMCT();
		for (int i = 0; i < soCTKH; i++)
		{
			q.Pop(ctkt);
			if (ctkt->getMCT() == MCT)
			{
				kt = 1;
				//break;
			}
			q.Push(ctkt);
		}
		if (kt == 1)
			cout << "\nDa ton tai MCT tren trong danh sach . ";
		else
		{
			q.Push(ct);
			soCTKH++;
		}
	}
}
void ListCTKH::Xoa()
{
	CongTrinhKhoaHoc *ct = NULL;
	int kt = 0;
	string MCT;
	cin.ignore();
	cout << "\nNhap vao id ban muon xoa . ";
	getline(cin, MCT);
	for (int i = 0; i < soCTKH; i++)
	{
		q.Pop(ct);
		if (ct->getMCT() == MCT)
		{
			kt = 1;
			continue;
		}

		q.Push(ct);
	}
	if (kt == 1)
		soCTKH--;
	if (kt == 0)
		cout << "\nKhong ton tai MCT ban muon xoa . ";
}
void ListCTKH::CapNhat()
{
	int kt = 0;
	CongTrinhKhoaHoc *ct = NULL;
	string MCT;
	cin.ignore();
	cout << "\nNhap id ban muon cap nhat . ";
	getline(cin, MCT);
	for (int i = 0; i < soCTKH; i++)
	{
		q.Pop(ct);
		if (ct->getMCT() == MCT)
		{
			ct->Nhap();
		}
		q.Push(ct);
	}
	 
}
void ListCTKH::TimKiem()
{
	int kt = 0;
	string MCT;
	CongTrinhKhoaHoc *ct = NULL;
	cin.ignore();
	cout << "\nNhap vao id ban muon tim kiem . ";
	getline(cin, MCT);
	for (int i = 0; i < soCTKH; i++)
	{
		q.Pop(ct);
		if (ct->getMCT() == MCT)
		{
			kt = 1;
			cout << "\nma cong trinh ban muon tim kiem la : " << endl;
			cout << setw(10) << "MCT" << setw(25) << "Nam XB" << setw(15) << "KVXB" <<setw(25)<<"ten loai sach/ten CT"<<setw(20)<<"so tac gia"<<  endl;
			ct->Xuat();
		}
		q.Push(ct);
	}
	if (kt == 0)
		cout << "\nKhong ton taicong nao co ma id nhu tren trong danh sach";
}
void ListCTKH::operator=(const ListCTKH p)
{
	tenTG = p.tenTG;
	soCTKH = p.soCTKH;
}
istream & operator >> (istream & i, ListCTKH &ct)
{
	string tenTG;
	//cout << "\nNhap danh sach khoi tao:";
	cout << "\nNhap ten tac gia: ";
	getline(i, ct.tenTG);
	return i;
}
ostream & operator <<(ostream &o, ListCTKH &ct)
{
	o << "\nten tac gia:";	
	return o;
}
