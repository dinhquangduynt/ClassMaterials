#include "List.h"

//bool TD(double left, double rigth) {
//	if (left > rigth)
//		return true;
//	return false;
//}
////tang dan
//bool GD(double left, double rigth) {
//	if (left < rigth)
//		return true;
//	return false;
//}
int main()
{
	
	NhanVien nv;
	List list;
	int luachon,vt,lc;
	do {
		cout << "\n\n\t\t\t\t\t" << "==================MENU==================" << endl;
		cout << "\t\t\t\t\t" << "========================================" << endl;
		cout << "\t\t\t\t\t" << "=====1. Nhap moi danh sach nhan vien====" << endl;
		cout << "\t\t\t\t\t" << "=====2. Xuat danh sach nhan vien========" << endl;
		cout << "\t\t\t\t\t" << "=====3. Them vao danh sach==============" << endl;
		cout << "\t\t\t\t\t" << "=====4. Cap nhat thong tin nhan vien====" << endl;
		cout << "\t\t\t\t\t" << "=====5. Xoa=============================" << endl;
		cout << "\t\t\t\t\t" << "=====6. Tim Kiem theo luong=============" << endl;
		cout << "\t\t\t\t\t" << "=====7. Sap xep theo luong==============" << endl;
		cout << "\t\t\t\t\t" << "=====0. Thoat===========================" << endl;
		cout << "\tNhap lua chon cua ban: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			cin >> list;
			cout << endl;
			break;
		case 2:
		//	cin.ignore();
			cout << list;
			break;
		case 3:		
		{
			cout << "\nBan muon them o vi tri nao(1-dau, 2-bat ki, 3-cuoi): ";
			cin >> lc;
			if (lc == 1)
			{
				cout << "Nhap Nhan vien ban can them: ";
				cin >> nv;
				list.Themdau(nv);
			}
			if (lc == 2)
			{
				cout << "\Nhap vi tri muon them: ";
				cin >> vt;
				cout << "Nhap Nhan vien ban can them: ";
				cin >> nv;
				list.Thembatki(nv, vt);
			}

		    if (lc == 3)
			{
				cout << "Nhap Nhan vien ban can them: ";
				cin >> nv;
				list.Themcuoi(nv);
			}
			break;
		}
		case 4:
			//cin.ignore();
			cout << "\nNhap nhan vien co ma so can cap nhat: ";
			cin >> nv.masonhanvien;
			list.Capnhat(nv.masonhanvien);
			break;
		case 5: 
		{
			cout << "\nBan muon xoa o vi tri nao(1-dau, 2-bat ki, 3-cuoi): ";
			cin >> lc;
			if (lc == 1)
			{
				list.Xoadau();
			}
			if (lc == 2)
			{
				cout << "\Nhap vi tri can xoa: ";
				cin >> vt;
				list.Xoabatki(vt);
				
			}

			if (lc == 3)
			{
				list.Xoacuoi();
			}
			break;
		}
		case 6:			
			{ 
			   // list.Binarysearch1(nv.luong);
			cout << list.Binarysearch1(nv,nv.luong);
				break;
			}
		case 7:
			
			list.Sapxep();
			cout << "Danh sach nhan vien sau khi duoc sap xep: \n" << list;
			break;
		}
		
	} while (luachon != 0);
	

	system("pause");
	return 0;
}