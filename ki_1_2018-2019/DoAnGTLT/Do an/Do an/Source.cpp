#include<iostream>
using namespace std;
#include<vector>
#include <string>
#include <fstream>


struct danhba
{
	string donvi;
	string diachi;
	string sodienthoai;
};
typedef struct danhba  DanhBa;

struct tentinh
{
	int sott;
	string tinh;
	vector<DanhBa> ds_danhba;
};
typedef struct  tentinh TenTinh;

void Doc_Ten_Tinh(ifstream &file, TenTinh &TT)
{
	file >> TT.sott;
	getline(file, TT.tinh);
}

void Doc_Ten_Danh_Ba(ifstream &file, DanhBa &DB)
{   
	getline(file, DB.donvi, '|');
	getline(file, DB.diachi, '|');
	getline(file, DB.sodienthoai);
}

void Doc_Full(ifstream &file, vector<TenTinh> &ds_tentinh)
{
	DanhBa db;
	while (file.eof() == false)
	{
		TenTinh tt;
		Doc_Ten_Tinh(file, tt);
		int n;
		file >> n;
		string temp;
		getline(file, temp);
		
		for (int i = 1; i <= n; i++)
		{
			
			Doc_Ten_Danh_Ba(file, db);
			getline(file, temp);
			tt.ds_danhba.push_back(db);
		}
		ds_tentinh.push_back(tt);
	}
}

void Xuat_Ten_Tinh(TenTinh tt)
{
	cout << "\nSo thu tu: " << tt.sott;
	cout << "\nTen Tinh: " << tt.tinh;

}

void Xuat_Danh_Ba(DanhBa db)
{
	cout << "\nTen don vi " << db.donvi;
	cout <<"\nDia chi " << db.diachi;
	cout << "\nSo dien thoai" << db.sodienthoai;
}

void Xuat(vector <TenTinh> ds)
{
	for (int i = 0; i < ds.size(); i++)
	{
		Xuat_Ten_Tinh(ds[i]);
		for (int j = 0; j <ds[i].ds_danhba.size(); j++)
		{
			Xuat_Danh_Ba(ds[i].ds_danhba[j]);
		}
	}
}

int main()
{
	ifstream file;
	file.open("DANHBA.TXT", ios_base::in);
	/*TenTinh tt;
	Doc_Ten_Tinh(file, tt);
	Xuat_Ten_Tinh(tt);
	DanhBa db;
	Doc_Ten_Danh_Ba(file, db);
	Xuat_Danh_Ba(db);*/
	vector <TenTinh> ds_tentinh;
	Doc_Full(file, ds_tentinh);
	Xuat(ds_tentinh);
	file.close();
	system("pause");
	return 0;
}