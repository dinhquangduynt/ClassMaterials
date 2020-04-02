#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

struct ThueBao {
	string TenCoQuan;
	string DiaChi;
	string SoDienThoai;
};

struct QuanLyThueBao {
	int n;
	ThueBao *listThueBaoTungTinh;
	string TenTinh;
};

struct QuanLyTinh {
	int n;
	QuanLyThueBao *listTinh;
};

string DocTenCuaMotTinh(ifstream &FileIn) {
	string tentinh;
	getline(FileIn, tentinh);
	return tentinh;
}

void DocThongTinCuaMotThueBao(ifstream &FileIn, ThueBao &dv) {
	getline(FileIn, dv.TenCoQuan, ',');
	FileIn.seekg(1, 1);
	getline(FileIn, dv.DiaChi, ',');
	FileIn.seekg(1, 1);
	getline(FileIn, dv.SoDienThoai);
}

void DocDanhSachThueBao(ifstream &FileIn, QuanLyThueBao &ds) {
	for (int i = 0; i < ds.n; i++) {
		DocThongTinCuaMotThueBao(FileIn, ds.listThueBaoTungTinh[i]);
	}
}


int XacDinhSoPhanTuCuaMang(ifstream &FileIn) {
	int n;
	FileIn >> n;
	return n;
}

void DocTinh(ifstream &FileIn, QuanLyThueBao &listTinh) {
	listTinh.TenTinh = DocTenCuaMotTinh(FileIn);
	listTinh.n = XacDinhSoPhanTuCuaMang(FileIn);
	listTinh.listThueBaoTungTinh = new ThueBao[listTinh.n];
	FileIn.ignore();			
	DocDanhSachThueBao(FileIn, listTinh);
}
void DocDanhSachTinh(ifstream &FileIn, QuanLyTinh &ds) {
	for (int i = 0; i < ds.n; i++) {
		DocTinh(FileIn, ds.listTinh[i]);
	}
}

void XuatTatCaThueBaoRaFile(ofstream &FileOut, QuanLyTinh ds) {
	FileOut << ds.n << endl;
	for (int i = 0; i < ds.n; i++) {
		FileOut << ds.listTinh[i].TenTinh << endl;
		FileOut << ds.listTinh[i].n << endl;
		for (int j = 0; j < ds.listTinh[i].n; j++) {
			FileOut << ds.listTinh[i].listThueBaoTungTinh[j].TenCoQuan << ", " <<
				 ds.listTinh[i].listThueBaoTungTinh[j].DiaChi << ", "
				<< ds.listTinh[i].listThueBaoTungTinh[j].SoDienThoai<< endl;
		}
	}
}

int dem1 = 0;
void LietKeThueBaoTungTinh(QuanLyTinh listTinh, string TenTinh) {
	cout << "--Danh sach thue bao tinh: " << TenTinh << ":" << endl;
	for (int i = 0; i < listTinh.n; i++) {
		if (listTinh.listTinh[i].TenTinh == TenTinh) {
		for (int j = 0; j < listTinh.listTinh[i].n; j++) {
			
				//cout << "+Thue bao thu " << j + 1 << ":" << endl;
				cout<< setw(15) << listTinh.listTinh[i].listThueBaoTungTinh[j].TenCoQuan << "  |  " 
					<< setw(20) << listTinh.listTinh[i].listThueBaoTungTinh[j].DiaChi << "  |  "
					<< setw(20) << listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai << endl;
				dem1 = dem1 + 1;
			}			
		}
	}
	if (dem1 == 0) {
		cout << "Khong co tinh ban tim!" << endl;
	}
}


void LietKeTatCaThueBao(QuanLyTinh listTinh) {
	cout << "Tat ca thue bao: " << endl;
	for (int i = 0; i < listTinh.n; i++) {
		cout << endl;
		cout << "--" << listTinh.listTinh[i].TenTinh << ":";
		for (int j = 0; j < listTinh.listTinh[i].n; j++) {
			cout << endl;
			//cout << "+Thue bao thu: " << j + 1 << endl;
			cout << setw(15) << listTinh.listTinh[i].listThueBaoTungTinh[j].TenCoQuan << "   |   " 
				 << setw(20) << listTinh.listTinh[i].listThueBaoTungTinh[j].DiaChi << "   |   " 
				 << setw(20) << listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai;
		}
		cout << endl;
	}
}




void AddThemThueBao(QuanLyThueBao &dstb, string TenTinh, int n) {
	bool ktra;
	dstb.n = n;
	dstb.listThueBaoTungTinh = new ThueBao[dstb.n];
	dstb.TenTinh = TenTinh;
	for (int i = 0; i < dstb.n; i++) {
		do {
			ktra = true;
			cout << "Nhap thue bao thu " << i + 1 << endl;
			cout << "Nhap Dia chi: ";
			getline(cin, dstb.listThueBaoTungTinh[i].DiaChi);
			cout << "Nhap Ten don vi: ";
			//cin.ignore();
			getline(cin, dstb.listThueBaoTungTinh[i].TenCoQuan);
			cout << "Nhap So dien thoai: ";
			getline(cin, dstb.listThueBaoTungTinh[i].SoDienThoai);
			fflush(stdin);
			for (int j = 0; j < i; j++) {
				if (dstb.listThueBaoTungTinh[j].SoDienThoai == dstb.listThueBaoTungTinh[i].SoDienThoai) {
					ktra = false;
					cout << "So dien thoai bi trung!" << endl;
					break;
				}
			}
		} while (ktra == false);
	}
}

bool KiemTraTinhCoTonTai(QuanLyTinh &ds, string TenTinh) {
	for (int i = 0; i < ds.n; i++) {
		if (ds.listTinh[i].TenTinh == TenTinh) return false;
	}
	return true;
}

void AddThemMotTinh(QuanLyTinh &ds, QuanLyThueBao &qltb) {
	QuanLyThueBao *dsm = new QuanLyThueBao[ds.n];
	for (int i = 0; i < ds.n; i++) {
		dsm[i].TenTinh = ds.listTinh[i].TenTinh;
		dsm[i].listThueBaoTungTinh = ds.listTinh[i].listThueBaoTungTinh;
		dsm[i].n = ds.listTinh[i].n;
	}
	delete[] ds.listTinh;
	ds.n = ds.n + 1;
	ds.listTinh = new QuanLyThueBao[ds.n];
	for (int j = 0; j < ds.n - 1; j++) {
		ds.listTinh[j].TenTinh = dsm[j].TenTinh;
		ds.listTinh[j].n = dsm[j].n;
		ds.listTinh[j].listThueBaoTungTinh = dsm[j].listThueBaoTungTinh;
	}
	ds.listTinh[ds.n - 1].listThueBaoTungTinh = qltb.listThueBaoTungTinh;
	ds.listTinh[ds.n - 1].TenTinh = qltb.TenTinh;
	ds.listTinh[ds.n - 1].n = qltb.n;
}

bool KiemTraSDTCoTonTai(QuanLyTinh &ds, string TenTinh, string sdt) {
	for (int i = 0; i < ds.n; i++) {
		for (int j = 0; j < ds.listTinh[i].n; j++) {
			if (ds.listTinh[i].listThueBaoTungTinh[j].SoDienThoai == sdt) {
				return false;
				break;
			}
		}
	}
	return true;
}

void AddMotThueBaoVaoMotTinh(QuanLyTinh &ds, string TenTinh, ThueBao &tb) {	
	int temp = 0;
	for (int i = 0; i < ds.n; i++) {
		if (ds.listTinh[i].TenTinh == TenTinh) {
			temp = temp + 1;
			ThueBao *dsm = new ThueBao[ds.listTinh[i].n];
			for (int j = 0; j < ds.listTinh[i].n; j++) {
				dsm[j].DiaChi = ds.listTinh[i].listThueBaoTungTinh[j].DiaChi;
				dsm[j].TenCoQuan = ds.listTinh[i].listThueBaoTungTinh[j].TenCoQuan;
				dsm[j].SoDienThoai = ds.listTinh[i].listThueBaoTungTinh[j].SoDienThoai;
			}
			delete[] ds.listTinh[i].listThueBaoTungTinh;
			ds.listTinh[i].n = ds.listTinh[i].n + 1;
			ds.listTinh[i].listThueBaoTungTinh = new ThueBao[ds.listTinh[i].n];
			for (int k = 0; k < ds.listTinh[i].n - 1; k++) {
				ds.listTinh[i].listThueBaoTungTinh[k].DiaChi = dsm[k].DiaChi;
				ds.listTinh[i].listThueBaoTungTinh[k].TenCoQuan = dsm[k].TenCoQuan;
				ds.listTinh[i].listThueBaoTungTinh[k].SoDienThoai = dsm[k].SoDienThoai;
			}
			ds.listTinh[i].listThueBaoTungTinh[ds.listTinh[i].n - 1].DiaChi = tb.DiaChi;
			ds.listTinh[i].listThueBaoTungTinh[ds.listTinh[i].n - 1].SoDienThoai = tb.SoDienThoai;
			ds.listTinh[i].listThueBaoTungTinh[ds.listTinh[i].n - 1].TenCoQuan = tb.TenCoQuan;
			break;
		}
	}
	if (temp == 0) {
		cout << "Khong tim thay tinh ban yeu cau!!" << endl;
	}
}


void TimKiemThueBaoTheoTenCoQuan(QuanLyTinh listTinh, string tdv) {
	int dem = 0;
	for (int i = 0; i < listTinh.n; i++) {
		for (int j = 0; j < listTinh.listTinh[i].n; j++) {
			if (listTinh.listTinh[i].listThueBaoTungTinh[j].TenCoQuan == tdv) {
				cout << "--" << listTinh.listTinh[i].TenTinh << ":" << endl;
				cout << setw(15) << listTinh.listTinh[i].listThueBaoTungTinh[j].TenCoQuan << "  |  "
					 << setw(20) << listTinh.listTinh[i].listThueBaoTungTinh[j].DiaChi << "  |  "
					 << setw(20) << listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai << endl;
				dem = dem + 1;
			}
		}
	}
	if (dem == 0) {
		cout << "Khong tim thay thue bao co ten co quan ban tim!!" << endl;
	}
}

void TimKiemThueBaoTheoSoDienThoai(QuanLyTinh listTinh, string sdt) {
	int dem = 0;
	for (int i = 0; i < listTinh.n; i++) {
		for (int j = 0; j < listTinh.listTinh[i].n; j++) {
			if (listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai == sdt) {
				cout << "--" << listTinh.listTinh[i].TenTinh << ":" << endl;
				cout << setw(15) << listTinh.listTinh[i].listThueBaoTungTinh[j].TenCoQuan << "  |  "
					<< setw(20) << listTinh.listTinh[i].listThueBaoTungTinh[j].DiaChi << "  |  "
					<< setw(20) << listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai << endl;
				dem = dem + 1;
			}
		}
	}
	if (dem == 0) {
		cout << "Khong tim thay thue bao so dien thoai ban tim!!" << endl;
	}
}

void XoaMotTinh(QuanLyTinh &ds, string TenTinh) {
	int index = -1;
	for (int i = 0; i < ds.n; i++) {
		if (ds.listTinh[i].TenTinh == TenTinh) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "Khong co tinh ban can xoa!!" << endl;
	}
	else {
		int size = ds.n--;
		QuanLyThueBao *p1 = new QuanLyThueBao[size];
		for (int i = 0; i < ds.n; i++) {
			if (i < index) {
				p1[i] = ds.listTinh[i];
			}
			if (i >= index) {
				p1[i] = ds.listTinh[i + 1];
			}
		}
		delete[] ds.listTinh;
		ds.listTinh = new QuanLyThueBao[size];
		ds.listTinh = p1;
	}
}

void XoaMotThueBaoTrongMotTinh(QuanLyTinh &ds, string TenTinh, string sdt) {
	int index = -1;
	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < ds.n; i++) {
		if (ds.listTinh[i].TenTinh == TenTinh) {
			temp1 = temp1 + 1;
			for (int j = 0; j < ds.listTinh[i].n; j++) {
				if (ds.listTinh[i].listThueBaoTungTinh[j].SoDienThoai == sdt) {
					temp2 = temp2 + 1;
					index = j;
					break;
				}
			}
			break;
		}
	}
	if (temp1 == 0) {
		cout << "Khong co tinh ban tim!!" << endl;
	}
	else {
		if (temp2 == 0) {
			cout << "Khong co so dien thoai ban can xoa!!" << endl;
		}
		else {
			for (int i = 0; i < ds.n; i++) {
				if (ds.listTinh[i].TenTinh == TenTinh) {
					int size = ds.listTinh[i].n--;
					ThueBao *p1 = new ThueBao[size];
					for (int j = 0; j < ds.listTinh[i].n; j++) {
						if (j < index) {
							p1[j].DiaChi = ds.listTinh[i].listThueBaoTungTinh[j].DiaChi;
							p1[j].SoDienThoai = ds.listTinh[i].listThueBaoTungTinh[j].SoDienThoai;
							p1[j].TenCoQuan = ds.listTinh[i].listThueBaoTungTinh[j].TenCoQuan;
						}
						if (j >= index) {
							p1[j].DiaChi = ds.listTinh[i].listThueBaoTungTinh[j + 1].DiaChi;
							p1[j].SoDienThoai = ds.listTinh[i].listThueBaoTungTinh[j + 1].SoDienThoai;
							p1[j].TenCoQuan = ds.listTinh[i].listThueBaoTungTinh[j + 1].TenCoQuan;
							
						}						
					}
					delete[] ds.listTinh[i].listThueBaoTungTinh;
					ds.listTinh[i].listThueBaoTungTinh = new ThueBao[size];
					ds.listTinh[i].listThueBaoTungTinh = p1;
				}
			}	
		}
	}
}	

void CapNhatThueBao(QuanLyTinh &listTinh, string TenTinh, string sdt) {
	int temp = 0, temp1 = 0;
	for (int i = 0; i < listTinh.n; i++) {
		if (listTinh.listTinh[i].TenTinh == TenTinh) {
			for (int j = 0; j < listTinh.listTinh[i].n; j++) {
				if (listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai == sdt) {
					cout << "Thue bao can cap nhat: " << endl;
					cout << setw(15) << listTinh.listTinh[i].listThueBaoTungTinh[j].TenCoQuan << "   |   "
						<< setw(20) << listTinh.listTinh[i].listThueBaoTungTinh[j].DiaChi << "   |   "
						<< setw(20) << listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai << endl;
					cout << "Nhap ten co quan moi: ";
					getline(cin, listTinh.listTinh[i].listThueBaoTungTinh[j].TenCoQuan);
					cout << "Nhap dia chi moi: ";
					getline(cin, listTinh.listTinh[i].listThueBaoTungTinh[j].DiaChi);
					cout << "Nhap so dien thoai moi: ";
					getline(cin, listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai);
					temp += 1;
				}
			}
			temp1 += 1;
		}
		
	}
	if (temp == 0 && temp1 != 0) {
		cout << "Khong co thue bao co ten co quan ban can cap nhat!" << endl;
	}
	if (temp1 == 0) {
		cout << "Khong co ten tinh ban can tim!" << endl;
	}
}

void myswap(ThueBao &tb1, ThueBao &tb2) {
	ThueBao temp;
	temp.DiaChi = tb1.DiaChi;
	temp.SoDienThoai = tb1.SoDienThoai;
	temp.TenCoQuan = tb1.TenCoQuan;
	tb1.DiaChi = tb2.DiaChi;
	tb1.SoDienThoai = tb2.SoDienThoai;
	tb1.TenCoQuan = tb2.TenCoQuan;
	tb2.DiaChi = temp.DiaChi;
	tb2.SoDienThoai = temp.SoDienThoai;
	tb2.TenCoQuan = temp.TenCoQuan;
}

void SapXepNoiBotGD(QuanLyTinh &listTinh) {
	for (int i = 0; i < listTinh.n; i++) {
		for (int j = 0; j < listTinh.listTinh[i].n - 1; j++) {
			for(int k = listTinh.listTinh[i].n - 1; k >j; k--){
				if (listTinh.listTinh[i].listThueBaoTungTinh[j].TenCoQuan < listTinh.listTinh[i].listThueBaoTungTinh[k].TenCoQuan) {
					myswap(listTinh.listTinh[i].listThueBaoTungTinh[j], listTinh.listTinh[i].listThueBaoTungTinh[k]);
				}
			}
			
		}
	}
}

void SapXepNoiBotTD(QuanLyTinh &listTinh) {
	for (int i = 0; i < listTinh.n; i++) {
		for (int j = 0; j < listTinh.listTinh[i].n - 1; j++) {
			for (int k = listTinh.listTinh[i].n - 1; k > j; k--) {
				//for (int k = j + 1; k < listTinh.listTinh[i].n; k++) {
				if (listTinh.listTinh[i].listThueBaoTungTinh[j].TenCoQuan > listTinh.listTinh[i].listThueBaoTungTinh[k].TenCoQuan) {
					myswap(listTinh.listTinh[i].listThueBaoTungTinh[j], listTinh.listTinh[i].listThueBaoTungTinh[k]);
				}
			}

		}
	}
}

void SapXepNoiBotSDT(QuanLyTinh &listTinh) {
	for (int i = 0; i < listTinh.n; i++) {
		for (int j = 0; j < listTinh.listTinh[i].n - 1; j++) {
			for (int k = listTinh.listTinh[i].n - 1; k > j; k--) {
				//for (int k = j + 1; k < listTinh.listTinh[i].n; k++) {
				if (listTinh.listTinh[i].listThueBaoTungTinh[j].SoDienThoai > listTinh.listTinh[i].listThueBaoTungTinh[k].SoDienThoai) {
					myswap(listTinh.listTinh[i].listThueBaoTungTinh[j], listTinh.listTinh[i].listThueBaoTungTinh[k]);
				}
			}

		}
	}
}


int main() {
	ThueBao tb;
	int choice, n;
	string str, str2, input="";
	QuanLyThueBao qltb;
	QuanLyTinh listTinh;
	ifstream FileIn;
	ofstream FileOut ("OUPUT.txt");
	cout << "Nhap vao duong dan den file input: ";
	cin >> input;
	FileIn.open(input, ios_base::in);
	//Doc du lieu tu file INPUT
	listTinh.n = XacDinhSoPhanTuCuaMang(FileIn);
	listTinh.listTinh = new QuanLyThueBao[listTinh.n];
	FileIn.ignore();
	DocDanhSachTinh(FileIn, listTinh);
	//Tim kiem thue bao bi trung
	//LietKeTatCaThueBaoTrungTrongMotTinh(listTinh);
	do {
		cout << endl;
		cout << "\t\t\t+=========================================================================+" << endl;
		cout << "\t\t\t|-------------------------------MENU--------------------------------------|" << endl;
		cout << "\t\t\t|-------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t|------1.  Liet ke tat ca thue bao cua tung tinh--------------------------|" << endl;
		cout << "\t\t\t|------2.  Liet ke tat ca thue bao----------------------------------------|" << endl;
		cout << "\t\t\t|------3.  Tim kiem thue bao theo so dien thoai---------------------------|" << endl;
		cout << "\t\t\t|------4.  Tim kiem thue bao theo ten co quan-----------------------------|" << endl;
		cout << "\t\t\t|------5.  Xuat tat ca thue bao ra file-----------------------------------|" << endl;
		cout << "\t\t\t|------6.  Them thue bao vao mot tinh da co-------------------------------|" << endl;
		cout << "\t\t\t|------7.  Them mot tinh moi----------------------------------------------|" << endl;
		cout << "\t\t\t|------8.  Xoa mot tinh---------------------------------------------------|" << endl;
		cout << "\t\t\t|------9.  Xoa mot thue bao trong mot tinh--------------------------------|" << endl;
		cout << "\t\t\t|------10. Cap nhat mot thue bao trong mot tinh---------------------------|" << endl;
		cout << "\t\t\t|------11. Sap xep thue bao trong mot tinh giam dan theo ten co quan------|" << endl;
		cout << "\t\t\t|------12. Sap xep thue bao trong mot tinh tang dan theo ten co quan------|" << endl;
		cout << "\t\t\t|------0.  Thoat----------------------------------------------------------|" << endl;
		cout << "\t\t\t|-------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t+=========================================================================+" << endl;
		cout << "\t\t\t|--------------------------CHON LUA CHON CUA BAN--------------------------|" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Nhap ten tinh ban muon tim: ";
			cin.ignore();
			getline(cin, str);
			LietKeThueBaoTungTinh(listTinh, str);
			break;
		case 2:
			LietKeTatCaThueBao(listTinh);
			break;
		case 3:
			cout << "Nhap so dien thoai ban muon tim: ";
			cin.ignore();
			getline(cin, str);
			TimKiemThueBaoTheoSoDienThoai(listTinh, str);
			break;
		case 4:
			cout << "Nhap ten co quan ban muon tim: ";
			cin.ignore();
			getline(cin, str);
			TimKiemThueBaoTheoTenCoQuan(listTinh, str);
			break;
		case 5:
			XuatTatCaThueBaoRaFile(FileOut, listTinh); 
			cout << "Xuat thanh cong!";
			break;
		case 6:
			cin.ignore();
			do {
				cout << "Nhap tinh ban muon them thue bao: ";
				getline(cin, str);
				if (KiemTraTinhCoTonTai(listTinh, str) == true) {
					cout << "Tinh khong ton tai. Vui long nhap lai!\n";
				}
			} while (KiemTraTinhCoTonTai(listTinh, str) == true);
			cout << "Nhap thong tin cua thue bao can them: " << endl;
			cout << "Ten don vi: ";			
			getline(cin, tb.TenCoQuan);

			cout << "Dia chi: ";
			getline(cin, tb.DiaChi);
			do {
				cout << "So dien thoai: ";
				getline(cin, tb.SoDienThoai);
				if (KiemTraSDTCoTonTai(listTinh, str, tb.SoDienThoai) == false) {
					cout << "So dien thoai da ton tai!" << endl;
				}
			} while (KiemTraSDTCoTonTai(listTinh, str, tb.SoDienThoai) == false);
			
			
			AddMotThueBaoVaoMotTinh(listTinh, str, tb);
			break;
		case 7:
			do {
				cout << "Nhap ten tinh ban them: ";
				cin.ignore();
				getline(cin, str);
				if (KiemTraTinhCoTonTai(listTinh, str) == false) {
					cout << "Tinh da ton tai. Vui long nhap lai!";
				}
			} while (KiemTraTinhCoTonTai(listTinh, str) == false);
			cout << "So thue bao ban can nhap: ";
			cin >> n;
			cin.ignore();
			cout << "Nhap thong tin cua cac thue bao: " << endl;
			AddThemThueBao(qltb, str, n);
			AddThemMotTinh(listTinh, qltb);
			break;
		case 8:
			cin.ignore();
			do {
				cout << "Nhap ten tinh ban muon xoa: ";
				getline(cin, str);
				if (KiemTraTinhCoTonTai(listTinh, str) == true) {
					cout << "Tinh khong ton tai. Vui long nhap lai!\n";
				}
			} while (KiemTraTinhCoTonTai(listTinh, str) == true);
			XoaMotTinh(listTinh, str);
			
			break;
		case 9:
			cout << "Nhap ten tinh ban tim: ";
			cin.ignore();
			getline(cin, str);
			cout << "Nhap so dien thoai ban can xoa: ";
			getline(cin, str2);
			XoaMotThueBaoTrongMotTinh(listTinh, str, str2);
			break;
		case 10:
			cout << "Nhap ten tinh cua thue bao do: ";
			cin.ignore();
			getline(cin, str);
			cout << "Nhap so dien thoai cua thue bao ban can cap nhat: ";
			getline(cin, str2);
			CapNhatThueBao(listTinh, str, str2);
			break;
		case 11:
			SapXepNoiBotGD(listTinh);
			break;
		case 12:
			SapXepNoiBotTD(listTinh);
			break;
		}
	}while(choice != 0);
	FileOut.close();
	FileIn.close();

	system("pause");
	return 0;
}



