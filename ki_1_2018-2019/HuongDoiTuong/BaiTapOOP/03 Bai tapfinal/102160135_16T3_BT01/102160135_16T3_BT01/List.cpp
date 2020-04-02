#include "List.h"
//#include "NhanVien.h"
//#include "date.h"
List::List(int n)
{
	this->n = n;
	this->data = new NhanVien[this->n];
}


void List::Show()
{
	for (int i = 0; i < this->n; i++)
	{
		cout << "\nNhan vien thu " << i + 1;
		(*(this->data + i)).ShowNv();
	}
}

//da nang hoa toan tu xuat
ostream& operator<<(ostream &o, const List &l)
{
	for (int j = 0; j < l.n; j++)
	{
		o << "\nNhan vien thu " << j + 1;
		o << l.data[j] << endl;
	}
	return o;
}


//da nang hoa toan tu nhap
istream & operator>>(istream &i, List &l)
{
	cin.ignore();
	int n;
	cout << "Nhap vao so nhan vien can tao: ";
	i >> n;
	l.n = n;
	l.data = new NhanVien[l.n];
	for (int j = 0; j < l.n; j++)
	{
		cout << "\nNhap nhan vien thu " << j + 1 << endl;
		i >> l.data[j];
	}
	return i;
}

// da nang hoa toan tu truy cap den phan tu []
NhanVien & List::operator[](int i)
{
	return data[i];
}

//them doi tuong cuoi danh sach
void List::Themcuoi(NhanVien &nv)
{
	NhanVien *p = new NhanVien[this->n];
	for (int i = 0; i < this->n; i++)
	{
		*(p + i) = *(this->data + i);
	}
	delete[] this->data;
	this->n++;
	this->data = new NhanVien[this->n];
	for (int i = 0; i < this->n - 1; i++)
	{
		*(this->data + i) = *(p + i);
	}
	*(this->data + (this->n - 1)) = nv;
}




//them doi tuong dau danh sach
void List::Themdau(NhanVien &nv)
{
	NhanVien *p = new NhanVien[this->n];
	for (int i = 0; i < this->n; i++)
	{
		*(p + i) = *(this->data + i);
	}
	delete[] this->data;
	this->n++;
	this->data = new NhanVien[this->n];
	this->data[0] = nv;
	for (int i = 1; i < this->n; i++)
	{
		//*(this->data + i) = *(p - i);
		*(this->data + i) = *(p + (i - 1));
	}
}


//them doi tuong o vi tri bat ki
void List::Thembatki(NhanVien &nv, int vt)
{
	NhanVien *p = new NhanVien[this->n];
	for (int i = 0; i < this->n; i++)
	{
		*(p + i) = *(this->data + i);
	}
	delete[] this->data;
	this->n++;
	this->data = new NhanVien[this->n];
	for (int i = 0; i < this->n; i++)
	{
		if (i < (vt - 1)) { //(i < vt - 1)
			//this->data[i] = p[i];
			*(this->data + i) = *(p + i);
		}
		if (i == (vt - 1)) {
			//this->data[i] = nv;
			*(this->data + i) = nv;
		}
		if (i > (vt - 1)) {
			//this->data[i] = p[i - 1];
			*(this->data + i) = *(p + (i - 1));
		}
	}
}

//Xoa doi tuong dau
void List::Xoadau()
{
	int m = this->n--;
	NhanVien *p = new NhanVien[m];
	for (int i = 0; i < this->n; i++)
	{
		*(p + i) = *(this->data + (i + 1));
	}
	delete[] this->data;
	this->data = new NhanVien[m];
	for (int i = 0; i < m; i++)
	{
		*(this->data + i) = *(p + i);
	}
}

//xoa doi tuong cuoi
void List::Xoacuoi()
{
	int m = this->n--;
	NhanVien *p = new NhanVien[m];
	for (int i = 0; i < this->n; i++)
	{
		*(p + i) = *(this->data + (this->n - 1));
	}
	delete[] this->data;
	this->data = new NhanVien[m];
	for (int i = 0; i < m; i++)
	{
		*(this->data + i) = *(p + i);
	}
}

//Xoa bat ki
void List::Xoabatki(int vt)
{
	int m = this->n--;
	NhanVien *p = new NhanVien[m];
	for (int i = 0; i < this->n; i++)
	{
		if (i < vt)
			*(p + i) = *(this->data + i);
		if (i >= vt)
			*(p + i) = *(this->data + (i + 1));
	}
	delete[] this->data;
	this->data = new NhanVien[m];
	for (int i = 0; i < m; i++)
	{
		*(this->data + i) = *(p + i);
	}
}

//Cap nhat
void List::Capnhat(string x)
{
	int fix;
	NhanVien nv;
	for (int i = 0; i < this->n; i++)
	{
		if (data[i].masonhanvien == x)
		{
			do
			{
				cout << "\n\t\t\tNhap 1 neu muon cap nhat lai ma so nhan vien!";
				cout << "\n\t\t\tNhap 2 neu muon cap nhat lai ten nhan vien!";
				cout << "\n\t\t\tNhap 3 neu muon cap nhat lai gioi tinh nhan vien!";
				cout << "\n\t\t\tNhap 4 neu muon cap nhat lai luong!";
				cout << "\n\t\t\tNhap 5 neu muon cap nhat lai ngay vao lam!";
				cout << "\n\t\t\tNhap 0 neu muon da cap nhat xong!";
				cout << "\nMoi nhap lua chon: ";
				cin >> fix;
				switch (fix)
				{
				case 1:
					cin.ignore();
					cout << "\nNhap ma so nhan vien: ";
					getline(cin, nv.masonhanvien);
					data[i].masonhanvien = nv.masonhanvien;
					break;
				case 2:
					cin.ignore();
					cout << "\nNhap ten nhan vien muon cap nhat: ";
					getline(cin, nv.hoten);
					data[i].hoten = nv.hoten;
					break;
				case 3:
					cout << "\nNhap gioi tinh muon cap nhat: ";
					cin >> nv.gioitinh;
					data[i].gioitinh = nv.gioitinh;
					break;
				case 4:
					cout << "\Nhap luong muon cap nhat: ";
					cin >> nv.luong;
					data[i].luong = nv.luong;
					break;
				case 5:
					cout << "\nNhap ngay vao lam muon cap nhat: ";
					nv.ngayvaolam.Nhapdate();
					data[i].ngayvaolam = nv.ngayvaolam;
					break;
				}
			} while (fix != 0);
		}
	}
}


//sap xep

void swap(NhanVien &x, NhanVien &y) {
	NhanVien temp = x; x = y; y = temp;
}
//tang dan
bool TD(double left, double rigth) {
	if (left > rigth)
		return true;
	return false;
}

//giam dan
bool GD(double left, double rigth) {
	if (left < rigth)
		return true;
	return false;
}



//sap xep
void List::shellsort(bool(*q)(double, double))
{
	for (int h = n / 2; h > 0; h /= 2)
	{
		for (int i = 0; i < n - h; i++)
		{
			int j = i;
			do
			{
				if (q(data[j].luong, data[j + h].luong))
				{
					swap(data[j], data[j + h]);
				}
				j = j - h;
			} while (q(data[j].luong, data[j + h].luong) && j >= 0);

		}
	}
}




//In danh sach theo tang hoac giam
void List::Sapxep()
{
	int lc;
	cout << "\nBan muon sap xep nhu the nao(1-tang dan, 2 giam dan): ";
	cin >> lc;
	if (lc == 1)
	{
		shellsort(TD);
	}
	if (lc == 2)
	{
		shellsort(GD);
	}
}

NhanVien List::Binarysearch(NhanVien &nv, double luong)
{
	
	cin.ignore();
	shellsort(TD);
	cout << "\nNhap vao luong can tim: ";
	cin >> nv.luong;
	int right, mid, left, dem = 0;
	left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;

		if (data[mid].luong < nv.luong) {
			left = mid + 1;
		}
		if (data[mid].luong > nv.luong)
		{

			right = mid - 1;
		}
		if (data[mid].luong == nv.luong) {
			return data[mid];
		}
	}
	return nv;
}

List::~List()
{
	delete[] this->data;
}
