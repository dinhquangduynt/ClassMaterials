#include<iostream>
#include"ListCTKH.h"
using namespace std;


void MeNu()
{
	cout << "\n======================================--> MeNu <--======================================";
	cout << "\n1 . them CTKH.";
	cout << "\n2 . Cap nhat .";
	cout << "\n3 . xem thong tin .";
	cout << "\n4 . Tim Kiem .";
	cout << "\n5 . Xoa";
	cout << "\n0 . Thoat .";
	cout << "\n=========================================================================================";
}
void LuaChon()
{
	ListCTKH list;
	if (list.getN()==0)
		cin >> list;
	int t=1;
	while(t) {
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
		case 5:
			list.Xoa();
			break;
		case 0:
			t = 0;
			break;
		default:
			break;
		}
		
	}
}
int main()
{
	LuaChon();
	system("pause");
	return 0;
}