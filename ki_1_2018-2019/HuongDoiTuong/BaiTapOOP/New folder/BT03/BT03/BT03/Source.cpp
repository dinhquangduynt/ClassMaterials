#include <iostream>
#include "LopSinhHoat.h"
#include "Lecturer.h"
#include "Node.h"
using namespace std;


void Menu();
void NhiemVu();



void Menu()
{
	cout << "\t\t DANH SACH CAC NHIEM VU " << endl;
	cout << "\t" << " 1.Hien thi thong tin" << endl;
	cout << "\t" << " 2.Chen dau" << endl;
	cout << "\t" << " 3.Chen cuoi " << endl;
	cout << "\t" << " 4.Chen vi tri bat ky" << endl;
	cout << "\t" << " 5.Cap nhat thong tin sinh vien" << endl;
	cout << "\t" << " 6.Xoa sinh vien" << endl;
	cout << "\t" << " 7.Tim kiem ten sinh vien" << endl;
	cout << "\t" << " 8.Sap xep doi tuong" << endl;
	cout << "\t" << " 0.Ket thuc" << endl;
	cout << endl;

}

void NhiemVu()
{
	LopSinhHoat x;
	cin >> x;  // khoi tao danh sach ban dau
	int chonnhiemvu = 0;

	do {
		Menu();

		do {
			cout << "Moi nhap nhiem vu muon thuc hien: ";
			cin >> chonnhiemvu;
			if (chonnhiemvu < 0 || chonnhiemvu > 8) cout << "Ban nhap khong dung! Moi nhap lai!" << endl;
		} while (chonnhiemvu < 0 || chonnhiemvu > 8);

		switch (chonnhiemvu) {
		case 1:
		{
			cout << " 1.HIEN THI THONG TIN " << endl;
			cout << x;
			break;
		}
		
		case 2:
		{
			cout << "2.CHEN DAU" << endl;
			cout << "Nhap thong tin muon chen " << endl;
			Node *n = new Node();
			n->Nhap();
			x.chendau(n);
			break;
		}
		case 3:
		{
			cout << "3.CHEN CUOI" << endl;
			cout << "Nhap thong tin muon chen " << endl;
			Node *n = new Node();
			n->Nhap();
			x.chencuoi(n);
			break;
		}
		case 4:
		{
			cout << "4.CHEN VI TRI BAT KY" << endl;
			int k;
			cout << "Nhap vi tri muon chen: ";
			cin >> k;
			cout << "Nhap thong tin muon chen " << endl;
			Node *n = new Node();
			n->Nhap();
			x.chenbatky(k,n);
			break;
		}
		case 5:
		{
			cout << "5.CAP NHAT THONG TIN SINH VIEN" << endl;
			int k;
			cout << "Nhap vi tri muon cap nhat: ";
			cin >> k;
			x.capnhat(k);
			break;
		}
		case 6:
		{
			cout << "6.XOA SINH VIEN" << endl;
			int k;
			cout << "Nhap vi tri muon xoa: ";
			cin >> k;
			x.xoa(k);
			break;
		}
		case 7:
		{
			cout << "7.TIM KIEM TEN SINH VIEN" << endl;
			x.timkiem();
			break;
		}
		}
	} while (chonnhiemvu != 0);

}

	
int main()
{
	NhiemVu();
	system("pause");
	return 0;
}

