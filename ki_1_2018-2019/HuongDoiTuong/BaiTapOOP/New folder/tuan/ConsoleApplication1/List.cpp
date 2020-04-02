#include "stdafx.h"
#include "List.h"
#include"NhanVien.h"
#include<string>
#include<iomanip>

List::List()
{
	n = 0;
	ds = new NhanVien[n];
}

List::~List()
{
	delete[]ds;
}

List::List(int n, NhanVien * ds)
{
	n = 2;
	ds = new NhanVien[n];
}


void List::OutputList()
{
	cout << setw(10) << "ID" << setw(25) << "TEN" << setw(15) << "GIOI TINH" << setw(20) << "LUONG" << setw(15) << "NGAY VAO LAM" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ds[i] << endl;
	}
}

void List::CapNhat()
{
	if (n > 0)
	{
		cin.ignore();
		string Ten;
		string Id;
		float luong;
		bool gt;
		cout << "\nNhap id muon cap nhat: ";
		getline(cin, Id);
		for (int i = 0; i < n; i++)
		{
			for (int i = 0; i < n; i++)
			{
				if (Id.compare((*(ds + i)).getId()) == 0)
				{
					cin.ignore();
					cout << "\nNhap Ten : ";
					getline(cin, Ten);
					ds[i].setId(Ten);
					cout << "\nNhap gt : ";
					cin >> gt;
					ds[i].setGioiTinh(gt);
					cout << "\nNhap luong : ";
					cin >> luong;
					ds[i].setSalary(luong);
				}
			}
		}
	}
	else {
		cout << "\nDanh sach chua co nhan vien nao ";
	}

}

void List::AddFirst()
{
	NhanVien nv;
	cout << "\nNhap nv . ";
	cin >> nv;
	NhanVien *b = new NhanVien[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = ds[i];
	}
	delete[]ds;
	ds = new NhanVien[n + 1];
	for (int i = 1; i < n + 1; i++)
	{
		ds[i] =b[i - 1];
	}
	delete[]b;
	ds[0] = nv;
	n = n + 1;
}

void List::AddLast()
{
	NhanVien nv;
	cout << "\nNhap nv : ";
	cin >> nv;
	NhanVien *b = new NhanVien[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = ds[i];
	}
	delete[]ds;
	ds = new NhanVien[n + 1];
	for (int i = 0; i < n; i++)
	{
		ds[i] = b[i];
	}
	delete[]b;
	ds[n] = nv;
	n = n + 1;
}

void List::AddAnyLocation()
{
	int vt;
	do {
		cout << "\nNhap vi tri can them ";
		cin >> vt;
		if (vt < 0 || vt > n - 1)
		{
			cout << "\nVi tri ban muon them phai > 0 va < " << n - 1;
		}
	} while (vt < 0 || vt >n - 1);
	NhanVien nv;
	cout << "\nNhap nv : ";
	cin >> nv;
	NhanVien *b = new NhanVien[n];
	for (int i = 0; i < n; i++)
	{
		b[i]= ds[i];
	}
	delete[]ds;
	ds = new NhanVien[n + 1];

	for (int i = n; i >= 0; i--)
	{
		if (i > vt)
		{
			ds[i] = b[i - 1];
		}
		else if (i == vt)
		{
			ds[vt]= nv;
		}
		else {
			ds[i] = b[i];
		}
	}
	delete[]b;
	n = n + 1;
}

void List::DeleteFirst()
{
	NhanVien *b = new NhanVien[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = ds[i];
	}
	delete[]ds;
	ds = new NhanVien[n - 1];
	n = n - 1;
	for (int i = 0; i < n; i++)
	{
		ds[i] = b[i+1];
	}
	delete[]b;
}

void List::DeleteLast()
{
	NhanVien *b = new NhanVien[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = ds[i];
	}
	delete[]ds;
	ds = new NhanVien[n - 1];
	n = n - 1;
	for (int i = 0; i < n ; i++)
	{
		ds[i] = b[i];
	}
	delete[]b;
}

void List::DeleteAnyLocation()
{
	int vt;
	do {
		cout << "\nNhap vi tri can xoa";
		cin >> vt;
		if (vt < 0 || vt > n - 1)
		{
			cout << "\nVi tri ban muon xoa phai > 0 va < " << n - 1;
		}
	} while (vt < 0 || vt >n - 1);
	NhanVien *b = new NhanVien[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = ds[i];
	}
	delete[]ds;
	ds = new NhanVien[n - 1];

	for (int i = 0; i < n ; i++)
	{
		if (i < vt)
		{ds[i] = b[i];
		}
		else if (i == vt)
		{
			continue;
		}
		else {
			ds[i-1]= b[i];
		}
	}
	delete[]b;
	n = n - 1;
}

int List::TimKiem(NhanVien * p, int N, float L)
{
	int Lo = 0;
	int Hi = N - 1;
	int Mid;
	while (p[Hi].getLuong() != p[Lo].getLuong() && (p[Lo].getLuong() <= L) && (p[Hi].getLuong() >= L))
	{
		Mid = Lo + (Hi - Lo) * (L - p[Lo].getLuong()) / (p[Hi].getLuong() - p[Lo].getLuong());
		if (p[Mid].getLuong() < L)
			Lo = Mid + 1;
		else if (p[Mid].getLuong() > L)
			Hi = Mid - 1;
		else
			return Mid;
	}
	return -1;
}

void List::SapXep(NhanVien * p, int n, bool ComFunct(float , float))
{
	int h = 1, i, j, c = 0;
	NhanVien x;
	while (h <= n / 3)
	{
		h = h * 3 + 1;
	}
	while (h > 0)
	{
		for (i = h; i < n; i++)
		{
			x = p[i];
			j = i;
			while (ComFunct(p[+j-h].getLuong(), x.getLuong()) && j > h - 1)
			{
				p[j] = p[j - h];
				j -= h;
			}
			p[j] = x;
		}
		h = (h - 1) / 3;
	}
}

bool TangDan(float a, float b)
{
	return a > b;
}

bool GiamDan(float a, float b)
{
	return a < b;
}

void List::LuaChonSapXep()
{
	int lc; 
	cout << "\nNhap vao lua chon sap xep cua ban . 1 tang dan , 2 giam dan . ";
	cin >> lc;
	if (lc == 1)
	{
		SapXep(ds, n, TangDan);
	}

	if (lc == 2)
	{
		SapXep(ds, n, GiamDan);
	}
}

void List::InTimKiem()
{
	SapXep(ds, n, TangDan);
	float Luong;
	cout << "\nNhap vao nhan vien co tien luong muon tim kiem : ";
	cin >> Luong;
	int tk = TimKiem(ds , n , Luong);
	if (tk == -1)
	{
		cout << "\nKhong co nhan vien co luong muon tim kiem ";
	}
	else
	{
		cout << ds [tk];
	}

}

NhanVien & List::operator[](int i)
{
	return ds[i];
}

ostream & operator<<(ostream &out, List & list)
{
	for (int i = 0; i < list.n; i++)
	{
		out <<list.ds[i];
	}
	return out;
}
