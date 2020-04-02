//#include"Date.h"
#include"QLNV.h"
int main() {

	QLNV l;
	NhanVien data;
	Date d;
	NVBC bc;
	int luachon, lc, vt;
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
		cout << "\t\t\t\t\t" << "=====0. Thoat===========================" << endl;
		cout << "\tNhap lua chon cua ban: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			cin >> l;
			//l.Nhap(l);
			//bc.Nhap();
			break;
		case 2:
			cout << l;
			//l.Xuat(l);
			//bc.Xuat();

			break;
		case 3:
		{
			cout << "\nBan muon them o vi tri nao(1-dau, 2-bat ki, 3-cuoi): ";
			cin >> lc;
			if (lc == 1)
			{
				cin.ignore();
				cout << "Nhap nhan vien thu ";
				cin >> data;
				NODE *node = l.CreateNode(data);
				l.Addhead(l, data);
			}
			if (lc == 2)
			{
				cin.ignore();
				cout << "Nhap nhan vien thu ";
				cin >> data;
				NODE *node = l.CreateNode(data);
				l.Add(l, data);
			}

			if (lc == 3)
			{
				cin.ignore();
				cout << "Nhap nhan vien thu ";
				cin >> data;
				NODE *node = l.CreateNode(data);
				l.Addtail(l, data);
			}
			break;
		}
		case 4:

			l.Update(l);
			break;
		case 5:
		{
			cout << "\nBan muon xoa o vi tri nao(1-dau, 2-bat ki, 3-cuoi): ";
			cin >> lc;
			if (lc == 1)
			{
				l.Deletehead(l);
			}
			if (lc == 2)
			{

				l.Delete(l);

			}

			if (lc == 3)
			{
				l.Deletetail(l);
			}
			break;
		}
		case 6:
		{
			l.Search(data, data.getMaso());
			break;
		}

		}

	} while (luachon != 0);

	system("pause");
	return 0;
}