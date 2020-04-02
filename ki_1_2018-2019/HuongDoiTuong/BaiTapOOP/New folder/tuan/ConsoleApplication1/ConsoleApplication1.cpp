// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"Date.h"
#include"NhanVien.h"
#include"List.h"
using namespace std;

void MeNu()
{
	cout << "\n======================================--> MeNu <--======================================";
	cout << "\n1 . Hien thi danh sach.";
	cout << "\n2 . Cap nhat thong tin .";
	cout << "\n3 . Them moi .";
	cout << "\n4 . Xoa .";
	cout << "\n5 . Tim Kiem . ";
	cout << "\n6 . Sap xep .";
	cout << "\n0 . Thoat .";
	cout << "\n=========================================================================================";
}


void LuaChon()
{
	int vt;
	List list;
	while (true)
	{
		MeNu();
		int lc;
		cout << "\nNhap vao lua chon cua ban ";
		cin >> lc;
		switch (lc)
		{
		case 1:
			list.OutputList();
			//cout << list ;
			break;
		case 2:
			list.CapNhat();
			break;
		case 3:
			cout << "\n 1 . them o dau ";
			cout << "\n bat ki . Them o giua ";
			cout << "\n 2 . Them o cuoi ";
			cout << "\nNhap vao vt can them ";
			cin >> vt;
			if (vt == 1)
				list.AddFirst();
			else if (vt == 2)
				list.AddLast();
			else
				list.AddAnyLocation();
			break;
		case 4:
			cout << "\n 1 . xoa o dau ";
			cout << "\n bat ki . xoa o giua";
			cout << "\n 2 . Xoa o cuoi ";
			cin >> vt;
			if (vt == 1)
				list.DeleteFirst();
			else if (vt == 2)
				list.DeleteLast();
			else
				list.DeleteAnyLocation();
			break;
		case 5:
			list.InTimKiem();
			break;
		case 6:
			list.LuaChonSapXep();
			break;
		default:
			break;
		}
		if (lc == 0)
			break;
	}
}
int main()
{
	LuaChon();
    return 0;
}

