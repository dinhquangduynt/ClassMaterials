#include "Date.h"
#include <iomanip>


Date::Date(int ngay, int thang, int nam)
{
	this->ngay = ngay;
	this->nam = nam;
	this->thang = thang;
}

int Date::getNgay()
{
	return ngay;
}

int Date::getThang()
{
	return thang;
}

int Date::getNam()
{
	return nam;
}

void Date::setNgay(int n)
{
	ngay = n;
}

void Date::setThang(int t)
{
	thang = t;
}

void Date::setNam(int nm)
{
	nam = nm;
}

void Date::Nhapdate()
{
	cout << "\nNhap nam: ";
	cin >> nam;
	do {
		cout << setw(3) << "Nhap thang: ";
		cin >> thang;
		if (thang < 0 || thang >12)
			cout << "\nVui long nhap lai thang!";
	} while (thang < 0 || thang >12);

	switch (thang)
	{

	case 2:
		if (nam % 4 == 0 && nam % 100 !=0 || nam % 100 == 0 && nam % 400 == 0)
		{
			do {
				cout << "\nNam " << nam << " la nam nhuan!";
				cout << setw(3) << "\nNhap ngay: ";
				cin >> ngay;
				if (ngay < 0 || ngay >29)
					cout << "\nVui long nhap lai ngay!";
			} while (ngay < 0 || ngay >29);
		}
		else
		{
			do {
				cout << "\nNam " << nam << " la nam khong nhuan!";
				cout << setw(3) << "\nNhap ngay: ";
				cin >> ngay;
				if (ngay < 0 || ngay >28)
					cout << "\nVui long nhap lai ngay!";
			} while (ngay < 0 || ngay >28);
		}
		break;

	case 4:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >30);
		break;

	case 6:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >30);
		break;


	case 9:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >30);
		break;

	case 11:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >30);
		break;
		
	default:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >31)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >31);
		break;

	}
}
void Date::Xuatdate()
{
	cout << ngay << "/" << thang << "/" << nam;

}

void Date::show()
{
	cout << "\nNgay: " << this->ngay;
	cout << "\nThang: " << this->thang;
	cout << "\nNam: " << this->nam << endl;
}

// da nang hoa toan tu xuat
ostream& operator<<(ostream &o, const Date &d)
{
	o << d.ngay << "/" << d.thang << "/" << d.nam << endl;
	return o;
}

//da nang hoa toan tu nhap
istream& operator>>(istream &i,Date &d)
{

	cout << "\nNhap nam: ";
	i >> d.nam;

	do {
		cout << setw(3) << "Nhap thang: ";
		i >> d.thang;
		if (d.thang < 0 || d.thang >12)
			cout << "\nVui long nhap lai thang!";
	} while (d.thang < 0 || d.thang >12);

	switch (d.thang)
	{
;
	case 2:
		if (d.nam % 4 == 0 && d.nam % 100 != 0 || d.nam % 100 == 0 && d.nam % 400 == 0) {
			do {
				cout << "nam " << d.nam << " la nam nhuan!";
				cout << setw(3) << "\nNhap ngay: ";
				i >> d.ngay;
				if (d.ngay < 0 || d.ngay >29)
					cout << "\nVui long nhap lai ngay!";
			} while (d.ngay < 0 || d.ngay >29);
		}
		else
		{
			do {
				cout << "nam " << d.nam << " la nam khong nhuan!";
				cout << setw(3) << "\nNhap ngay: ";
				i >> d.ngay;
				if (d.ngay < 0 || d.ngay >28)
					cout << "\nVui long nhap lai ngay!";
			} while (d.ngay < 0 || d.ngay >28);
		}
		break;

	case 4:
		do {
			cout << setw(3) << "Nhap ngay: ";
			i >> d.ngay;
			if (d.ngay < 0 || d.ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (d.ngay < 0 || d.ngay >30);
		break;

	case 6:
		do {
			cout << setw(3) << "Nhap ngay: ";
			i >> d.ngay;
			if (d.ngay < 0 || d.ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (d.ngay < 0 || d.ngay >30);
		break;

	case 9:
		do {
			cout << setw(3) << "Nhap ngay: ";
			i >> d.ngay;
			if (d.ngay < 0 || d.ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (d.ngay < 0 || d.ngay >30);
		break;

	case 11:
		do {
			cout << setw(3) << "Nhap ngay: ";
			i >> d.ngay;
			if (d.ngay < 0 || d.ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (d.ngay < 0 || d.ngay >30);
		break;
	
	default:
		do
		{
			cout << setw(3) << "Nhap ngay: ";
			i >> d.ngay;
			if (d.ngay < 0 || d.ngay >31)
				cout << "\nVui long nhap lai ngay!";
		} while (d.ngay < 0 || d.ngay >31);
		break;

	}
	return i;
}
Date::~Date()
{
}
