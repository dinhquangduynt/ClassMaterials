//#include"Date.h"
#include"QLNV.h"
int main() {

	QLNV l,l1;
	NhanVien *data = NULL;
	Date d;
	NVBC bc;
	int luachon, lc, vt,mm,i;
	l.Init();
	do {
		cout << "\n\n\t\t\t\t\t" << "==================MENU==================" << endl;
		cout << "\t\t\t\t\t" << "========================================" << endl;
		cout << "\t\t\t\t\t" << "=====1. Nhap moi danh sach nhan vien====" << endl;
		cout << "\t\t\t\t\t" << "=====2. Xuat danh sach nhan vien========" << endl;
		cout << "\t\t\t\t\t" << "=====3. Them vao danh sach==============" << endl;
		cout << "\t\t\t\t\t" << "=====4. Cap nhat thong tin nhan vien====" << endl;
		cout << "\t\t\t\t\t" << "=====5. Xoa=============================" << endl;
		cout << "\t\t\t\t\t" << "=====6. Tim Kiem theo ma so=============" << endl;
		cout << "\t\t\t\t\t" << "=====7. truy cap phan tu=============" << endl;
		cout << "\t\t\t\t\t" << "=====0. Thoat===========================" << endl;
		cout << "\tNhap lua chon cua ban: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			cin >> l;
			break;
		case 2:
			cout << l;
			break;
		case 3:
		{
			cout << "\nBan muon them o vi tri nao(1-dau, 2-bat ki, 3-cuoi): ";
			cin >> lc;
			if (lc == 1)
			{
				do
				{
					cout << "\n\t\t\t\t\t" << "=====1. Nhap NVHD====" << endl;
					cout << "\t\t\t\t\t" << "=====2. Nhap NVBC====" << endl;
					cout << "\nNhap lua chon cua ban: ";
					cin >> vt;
					if (vt != 1 && vt != 2)
					{
						cout << "\nVui long nhap lai";
					}
				} while (vt != 2 && vt != 1);

				if (vt == 1)
				{
					cout << "\nBan dang them nhan vien hop dong";
					NhanVien *nv = new NVHD;
					nv->Nhap();
					NODE *node = l.CreateNode(nv);					
					l.Addhead(*node);
				}
				if (vt == 2) {
					cout << "\nBan dang them nhan vien bien che";
					NhanVien *nv = new NVBC;
					nv->Nhap();
					NODE *node = l.CreateNode(nv);
					l.Addhead(*node);
				}

			}

			if (lc == 3)
			{
				do
				{
					cout << "\n\t\t\t\t\t" << "=====1. Nhap NVHD====" << endl;
					cout << "\t\t\t\t\t" << "=====2. Nhap NVBC====" << endl;
					cout << "\nNhap lua chon cua ban: ";
					cin >> vt;
					if (vt != 1 && vt != 2)
					{
						cout << "\nVui long nhap lai";
					}
				} while (vt != 2 && vt != 1);

				if (vt == 1)
				{
					cout << "\nBan dang them nhan vien hop dong";
					NhanVien *nv = new NVHD;
					nv->Nhap();
					NODE *node = l.CreateNode(nv);
					l.Addtail(node);
				}
				if (vt == 2) {
					cout << "\nBan dang them nhan vien bien che";
					NhanVien *nv = new NVBC;
					nv->Nhap();
					NODE *node = l.CreateNode(nv);
					l.Addtail(node);
				}
			}
			if (lc == 2)
			{
				do
				{
					cout << "\n\t\t\t\t\t" << "=====1. Nhap NVHD====" << endl;
					cout << "\t\t\t\t\t" << "=====2. Nhap NVBC====" << endl;
					cout << "\nNhap lua chon cua ban: ";
					cin >> vt;
					if (vt != 1 && vt != 2)
					{
						cout << "\nVui long nhap lai";
					}
				} while (vt != 2 && vt != 1);

				if (vt == 1)
				{
					cout << "\nBan dang them nhan vien hop dong";
					NhanVien *nv = new NVHD;
					nv->Nhap();
					NODE *node = l.CreateNode(nv);
					l.Add(node);
				}
				if (vt == 2) {
					cout << "\nBan dang them nhan vien bien che";
					NhanVien *nv = new NVBC;
					nv->Nhap();
					NODE *node = l.CreateNode(nv);
					l.Add(node);
				}
			}
			break;
		}
		case 4:

			l.Update();
			break;
		case 5:
		{
			cout << "\nBan muon xoa o vi tri nao(1-dau, 2-bat ki, 3-cuoi): ";
			cin >> lc;
			if (lc == 1)
			{
				l.Deletehead();
			}
			if (lc == 2)
			{

				l.Delete();

			}

			if (lc == 3)
			{
				l.Deletetail();
			}
			break;
		}
		case 6:
		{
			l.Search();
			break;
		}
		case 7:
			cout << "Nhap vi tri muon truy xuat: ";
			cin >> i;
			//cout << l[i];
		}
	}
	 while (luachon != 0);
	system("pause");
	return 0;
}