#include<iostream>
#include"ListCTKH.h"
//#include"CongTrinhKhoaHoc.h"
//#include"Sach.h"
//#include"BaiBao.h"
#include"queue.h"
using namespace std;


void MeNu()
{
	cout << "\n======================================--> MeNu <--======================================";
	cout << "\n1 . them CTKH.";
	cout << "\n2 . Cap nhat .";
	cout << "\n3 . xem thong tin .";
	cout << "\n4 . Xoa .";
	cout << "\n5 . Tim Kiem . ";
	cout << "\n6 . Sap xep .";
	cout << "\n0 . Thoat .";
	cout << "\n=========================================================================================";
}
void LuaChon()
{
	ListCTKH list;
	/*if (list.getN() != 0)
		cin >> list;
	while (true)
	{*/
		MeNu();
		int lc;
		cout << "\nNhap vao lua chon cua ban ";
		cin >> lc;
		switch (lc)
		{
		case 1:
			list.Them();
			break;
		case 2:
			list.CapNhat();
			break;
		case 3:
			list.Xuat();
			break;
		case 4:
			list.TimKiem();
			break;
		/*case 3:
			cout << "\n 1 . them o dau ";
			cout << "\n 2 . bat ki ";
			cout << "\n 3 . Them o cuoi ";
			cout << "\nNhap vao vt can them ";
			cin >> vt;
			if (vt == 1)
				list.AddFirst();
			else if (vt == 3)
				list.AddLast();
			else if (vt == 2)
				list.AddAnyLocation();
			break;
		case 4:
			cout << "\n 1 . xoa o dau ";
			cout << "\n 2 . xoa bat ki";
			cout << "\n 3 . Xoa o cuoi ";
			cout << "\nNhap vao vt can xoa ";
			cin >> vt;
			if (vt == 1)
				list.DeleteFirst();
			else if (vt == 3)
				list.DeleteLast();
			else if (vt == 2)
				list.DeleteAnyLocation();
			break;
		case 5:
			list.InTimKiem();
			break;
		case 6:
			list.LuaChonSapXep();
			break;*/
		default:
			break;
		}
		//if (lc == 0)
			//break;
	}
//}
int main()
{
	LuaChon();
	return 0;
}
