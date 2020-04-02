//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//struct thuebao {
//	string TenDonVi;
//	string DiaChi;
//	string SoDienThoai;
//};
//typedef struct thuebao ThueBao;
//struct quanlythuebao {
//	int n;
//	ThueBao *listThueBaoTungTinh;
//	string TenTinh;
//};
//
//typedef struct quanlythuebao QuanLyThueBao;
//
//struct quanlytinh {
//	int n;
//	QuanLyThueBao *listTinh;
//};
//typedef struct quanlytinh QuanLyTinh;
//
//string DocTenCuaMotTinh(ifstream &FileIn) {
//	string tentinh;
//	getline(FileIn, tentinh);
//	return tentinh;
//}
//
//void DocThongTinCuaMotThueBao(ifstream &FileIn, ThueBao &dv) {
//	getline(FileIn, dv.TenDonVi, ',');
//	FileIn.seekg(1, 1);
//	getline(FileIn, dv.DiaChi, ',');
//	FileIn.seekg(1, 1);
//	getline(FileIn, dv.SoDienThoai);
//}
//
//void DocDanhSachThueBao(ifstream &FileIn, QuanLyThueBao &ds) {
//	for (int i = 0; i < ds.n; i++) {
//		DocThongTinCuaMotThueBao(FileIn, ds.listThueBaoTungTinh[i]);
//	}
//}
//
//// kiểm tra trùng số điện thoại
////bool Kiem_Tra_So_Dien_Thoai(ifstream &FileIn,QuanLyThueBao &ds ,QuanLyThueBao &listTinh, string sdt)
////{
////	for (int i=0; i<ds.n-1; i++)
////	{
////		listTinh.TenTinh = DocTenCuaMotTinh(FileIn);
////		listTinh.n = XacDinhSoPhanTuCuaMang(FileIn);
////		listTinh.listThueBaoTungTinh = new ThueBao[listTinh.n];
////		FileIn.ignore();
////		for (int j = ds.n; j >0; j--)
////		{
////			if()
////		}
////
////	}
////	return false;
////	/*listTinh.TenTinh = DocTenCuaMotTinh(FileIn);
////	listTinh.n = XacDinhSoPhanTuCuaMang(FileIn);
////	listTinh.listThueBaoTungTinh = new ThueBao[listTinh.n];
////	FileIn.ignore();
////	DocDanhSachThueBao(FileIn, listTinh);*/
////}
//
//void XuatThongTinCuaMotThueBao(ThueBao tb) {
//	cout << "Ten don vi: " << tb.TenDonVi << endl;
//	cout << "Dia chi: " << tb.DiaChi << endl;
//	cout << "So dien thoai: " << tb.SoDienThoai << endl;
//}
//
//void XuatDanhSachThueBao(QuanLyThueBao listTinh) {
//	for (int i = 0; i < listTinh.n; i++) {
//		cout << listTinh.TenTinh << endl;
//		cout << "Thue bao thu " << i + 1 << endl;
//		XuatThongTinCuaMotThueBao(listTinh.listThueBaoTungTinh[i]);
//		cout << "\n\n";
//	}
//}
//
//int XacDinhSoPhanTuCuaMang(ifstream &FileIn) {
//	int n;
//	FileIn >> n;
//	return n;
//}
//
//void DocTinh(ifstream &FileIn, QuanLyThueBao &listTinh) {
//	listTinh.TenTinh = DocTenCuaMotTinh(FileIn);
//	listTinh.n = XacDinhSoPhanTuCuaMang(FileIn);
//	listTinh.listThueBaoTungTinh = new ThueBao[listTinh.n];
//	FileIn.ignore();
//	DocDanhSachThueBao(FileIn, listTinh);
//	//XuatDanhSachThueBao(listTinh);
//}
//void DocDanhSachTinh(ifstream &FileIn, QuanLyTinh &ds) {
//	for (int i = 0; i < ds.n; i++) {
//		DocTinh(FileIn, ds.listTinh[i]);
//	}
//}
////khánh code
//
//void LietKeThueBaoTungTinh(QuanLyTinh listTinht, int Tinh) {
//	cout << "Danh sach thue bao tinh: " << listTinht.listTinh[Tinh].TenTinh << endl;
//	for (int i = 0; i < listTinht.listTinh[Tinh].n; i++) {
//		cout << "Thue bao thu " << i + 1 << ":" << endl;
//		cout << listTinht.listTinh[Tinh].listThueBaoTungTinh[i].DiaChi << "  |  "
//			<< listTinht.listTinh[Tinh].listThueBaoTungTinh[i].SoDienThoai << "  |  "
//			<< listTinht.listTinh[Tinh].listThueBaoTungTinh[i].TenDonVi << endl;
//	}
//}
//
//void LietKeTatCaThueBao(QuanLyTinh listTinh) {
//	cout << "Tat ca thue bao: " << endl;
//	for (int i = 0; i < listTinh.n; i++) {
//		cout << endl;
//		cout << listTinh.listTinh[i].TenTinh;
//		for (int j = 0; j < listTinh.listTinh[i].n; j++) {
//			cout << endl;
//			cout << listTinh.listTinh[i].listThueBaoTungTinh[j].DiaChi << "   |   "
//				<< listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai << "   |   "
//				<< listTinh.listTinh[i].listThueBaoTungTinh[j].TenDonVi << endl;
//		}
//	}
//}
////=======================================tìm kiếm thuê bao trùng nhau=======================================
//void LietKeTatCaThueBaoTrungTrongMotTinh(QuanLyTinh listTinh) {
//
//	cout << "Tat ca thue bao bi trung: " << endl;
//	for (int i = 0; i < listTinh.n; i++) {
//		int sothuebaotrung = 0;
//		cout << endl;
//		cout << listTinh.listTinh[i].TenTinh;
//		cout << endl;
//		int size = listTinh.listTinh[i].n;
//		int b[1000];
//		for (int z = 0; z < size; z++)
//		{
//			b[i] = 1;
//		}
//		for (int j = 0; j < listTinh.listTinh[i].n - 1; j++) {//listTinh.listTinh[i].n -1
//			int kiemtra = 0;
//			int count = 0;	
//			if (b[j])
//			{
//				//b[j] == 0;
//				for (int k = j + 1; k < listTinh.listTinh[i].n; k++)
//				{
//					if (listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai == listTinh.listTinh[i].listThueBaoTungTinh[k].SoDienThoai)
//					{
//						// in thong tin cac thue bao bi trung
//						/*if (sothuebaotrung==0) {
//							cout << listTinh.listTinh[i].listThueBaoTungTinh[j].TenDonVi << "   |   "
//								<< listTinh.listTinh[i].listThueBaoTungTinh[j].DiaChi << "   |   "
//								<< listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai << endl;
//
//						}
//						if (b[k]== 0) {
//							cout << listTinh.listTinh[i].listThueBaoTungTinh[k].TenDonVi << "   |   "
//								<< listTinh.listTinh[i].listThueBaoTungTinh[k].DiaChi << "   |   "
//								<< listTinh.listTinh[i].listThueBaoTungTinh[k].SoDienThoai << endl;
//						}
//*/
//						kiemtra = kiemtra + 1;
//						sothuebaotrung = sothuebaotrung + 1;
//						count++;
//						b[k] = 0;
//					}
//					//else kiemtra = 0;
//				}
//				if ((count) != 0)
//				{
//					cout << "\nVui long xoa " << count+1
//						<< " thue bao " << listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai << " bi trung trong tinh "
//						<< listTinh.listTinh[i].TenTinh << endl;
//				}
//			}
//			
//			
//		}
//	}
//}
//int dem = 0;
//void TimKiemThueBaoTheoSoDienThoai(QuanLyTinh listTinh, string sdt) {
//	for (int i = 0; i < listTinh.n; i++) {
//		for (int j = 0; j < listTinh.listTinh[i].n; j++) {
//			if (listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai == sdt) {
//
//				cout << "Tinh: " << listTinh.listTinh[i].TenTinh << endl;
//				cout << listTinh.listTinh[i].listThueBaoTungTinh[j].DiaChi << "  |  "
//					<< listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai << "  |  "
//					<< listTinh.listTinh[i].listThueBaoTungTinh[j].TenDonVi << endl;
//
//				dem = dem + 1;
//			}
//		}
//	}
//	if (dem == 0) {
//		cout << "Khong tim thay thue bao so dien thoai ban tim!!" << endl;
//	}
//}
//
//void TimKiemThueBaoTheoTenDonVi(QuanLyTinh listTinh, string tdv) {
//	for (int i = 0; i < listTinh.n; i++) {
//		for (int j = 0; j < listTinh.listTinh[i].n; j++) {
//			if (listTinh.listTinh[i].listThueBaoTungTinh[j].TenDonVi == tdv) {
//				cout << "Tinh: " << listTinh.listTinh[i].TenTinh << endl;
//				cout << listTinh.listTinh[i].listThueBaoTungTinh[j].DiaChi << "  |  "
//					<< listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai << "  |  "
//					<< listTinh.listTinh[i].listThueBaoTungTinh[j].TenDonVi << endl;
//				dem = dem + 1;
//			}
//		}
//	}
//	if (dem == 0) {
//		cout << "Khong tim thay thue bao co ten don vi ban tim!!" << endl;
//	}
//}
//
//// hàm tìm hai số trùng nhau trong 1 tỉnh và yêu cầu xóa
//
//
//
//int main() {
//	int choice;
//	string str;
//	QuanLyTinh listTinh;
//	ifstream FileIn;
//	FileIn.open("INPUT.txt", ios_base::in);
//	listTinh.n = XacDinhSoPhanTuCuaMang(FileIn);
//	listTinh.listTinh = new QuanLyThueBao[listTinh.n];
//	FileIn.ignore();
//	DocDanhSachTinh(FileIn, listTinh);
//	do {
//		cout << endl;
//		cout << "\t\t\t\t\t" << "+=====================MENU======================+" << endl;
//		cout << "\t\t\t\t\t" << "|-----------------------------------------------|" << endl;
//		cout << "\t\t\t\t\t" << "|-----------------------------------------------|" << endl;
//		cout << "\t\t\t\t\t" << "|-----1. Liet ke tat ca thue bao cua tinh 1-----|" << endl;
//		cout << "\t\t\t\t\t" << "|-----2. Liet ke tat ca thue bao cua tinh 2-----|" << endl;
//		cout << "\t\t\t\t\t" << "|-----3. Liet ke tat ca thue bao cua tinh 3-----|" << endl;
//		cout << "\t\t\t\t\t" << "|-----4. Liet ke tat ca thue bao cua tinh 4-----|" << endl;
//		cout << "\t\t\t\t\t" << "|-----5. Liet ke tat ca thue bao cua tinh 5-----|" << endl;
//		cout << "\t\t\t\t\t" << "|-----6. Liet ke tat ca thue bao----------------|" << endl;
//		cout << "\t\t\t\t\t" << "|-----7. Tim kiem thue bao theo So dien thoai---|" << endl;
//		cout << "\t\t\t\t\t" << "|-----8. Tim kiem thue bao theo Ten don vi------|" << endl;
//		cout << "\t\t\t\t\t" << "|-----9. Tim kiem thue bao bi trung trong mot tinh------|" << endl;
//		cout << "\t\t\t\t\t" << "|-----0. Thoat----------------------------------|" << endl;
//		cout << "\t\t\t\t\t" << "|-----------------------------------------------|" << endl;
//		cout << "\t\t\t\t\t" << "|------------CHON LUA CHON CUA BAN--------------|" << endl;
//		cout << "\t\t\t\t\t" << "+===============================================+" << endl;
//
//		cout << "\nNhap lua chon cua ban: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			LietKeThueBaoTungTinh(listTinh, 0);
//			break;
//		case 2:
//			LietKeThueBaoTungTinh(listTinh, 1);
//			break;
//		case 3:
//			LietKeThueBaoTungTinh(listTinh, 2);
//			break;
//		case 4:
//			LietKeThueBaoTungTinh(listTinh, 3);
//			break;
//		case 5:
//			LietKeThueBaoTungTinh(listTinh, 4);
//			break;
//		case 6:
//			LietKeTatCaThueBao(listTinh);
//			break;
//		case 7:
//			cout << "Nhap so dien thoai ban muon tim: ";
//			cin.ignore();
//			getline(cin, str);
//			TimKiemThueBaoTheoSoDienThoai(listTinh, str);
//		case 8:
//			cout << "Nhap ten don vi ban muon tim: ";
//			cin.ignore();
//			getline(cin, str);
//			TimKiemThueBaoTheoTenDonVi(listTinh, str);
//		case 9:
//			LietKeTatCaThueBaoTrungTrongMotTinh(listTinh);
//		}
//	} while (choice != 0);
//
//	FileIn.close();
//	system("pause");
//	return 0;
//}
//
//
//
#include <iostream>
using namespace std;
int main() {
	int a[] = {10, 2, 30, 4, 5};
	int *p = a;
	p += 2;
	cout << *p << endl;
	//cout << p << endl;
	p--;
	cout << *p << endl;
	//cout << p << endl;
	*p++;
	cout << p << endl;
	//cout << p << endl;
	system("pause");
	return 0;
}