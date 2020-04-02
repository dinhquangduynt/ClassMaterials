#include "Date.h"
#include <iomanip>


Date::Date(int ngay, int thang, int nam)
{
	this->ngay = ngay;
	this->nam = nam;
	this->thang = thang;
}

void Date::Nhapdate()
{
	bool check = true;
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
	case 1:
		do
		{
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >31)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >31);
		break;
	case 2:
		do {
			check = true;
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if ((nam % 4 == 0 && nam % 100 == 0) || (nam % 400 == 0)) {
				if (ngay < 0 || ngay >29)
					cout << "\nVui long nhap lai ngay!";
				check = false;
			}
			else {
				if (ngay < 0 || ngay >28)
					cout << "\nVui long nhap lai ngay!";
				check = false;
			}

		} while (check == false);
		break;
	case 3:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >31)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >31);
		break;
	case 4:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >30);
		break;
	case 5:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >31)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >31);
		break;
	case 6:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >30);
		break;
	case 7:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >31)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >31);
		break;
	case 8:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >31)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >31);
		break;
	case 9:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >30);
		break;
	case 10:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >31)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >31);
		break;
	case 11:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >30)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >30);
		break;
	case 12:
		do {
			cout << setw(3) << "Nhap ngay: ";
			cin >> ngay;
			if (ngay < 0 || ngay >31)
				cout << "\nVui long nhap lai ngay!";
		} while (ngay < 0 || ngay >31);
		break;
	default:
		break;

	}
}
void Date::Xuatdate()
{
	cout << ngay << "/" << thang << "/" << nam << endl;

}

void Date::show()
{
	cout << "\nNgay: " << this->ngay;
	cout << "\nThang: " << this->thang;
	cout << "\nNam: " << this->nam << endl;
}