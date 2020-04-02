#include "MyString.h"



//ham mac dinh tao sau rong
MyString::MyString()
{
	this->n = n;
	data = new char[1];
	data[0] = '\0';

}

//chuyen char* sang MyString
MyString::MyString(const char *a)
{
	delete[] data;
	int i = 0;
	char c = '\0';
	while (a[i] != c) {
		i++;
	}
	this->n = i;
	data = new char[n + 1];
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	data[n] = '\0';
}

//ham sao chep
MyString::MyString(const MyString &s)
{
	this->n = s.n;
	data = new char[this->n + 1];

	for (int i = 0; i <= n; i++)
	{
		data[i] = s.data[i];
	}
}

//toan tu +
MyString MyString::operator+(const MyString &s)
{
	MyString temp;
	temp.n = this->n + s.n;
	temp.data = new char[temp.n + 1];
	for (int i = 0; i < n; i++) {
		temp.data[i] = this->data[i];
	}
	for (int i = 0; i <= s.n; i++)
	{
		temp.data[n + i] = s.data[i];
	}
	temp.data[temp.n] = '\0';
	return temp;
}

//toan tu & bi loi
MyString MyString::operator&(const MyString &s)
{

	MyString add;
	add.n = this->n + s.n;
	add.data = new char[add.n + 1];
	for (int i = 0; i < n; i++) {
		add.data[i] = this->data[i];
	}
	for (int i = 0; i < s.n; i++)
	{
		add.data[n + i] & s.data[i];
	}
	return add;
}

//toan tu gan =
MyString MyString::operator=(const MyString &s)
{
	delete[] data;
	this->n = s.n;
	data = new char[s.n + 1];
	for (int i = 0; i < s.n; i++)
	{
		data[i] = s.data[i];
	}
	data[s.n] = '\0';
	return *this;
}

//toan tu so sanh ==
bool MyString::operator==(const MyString &s)
{
	if (this->n != s.n) return false;
	for (int i = 0; i < s.n; i++)
	{
		if (this->data[i] != s.data[i])
			return false;
		break;
	}
	return true;
}

//toan tu so sanh !=
bool MyString::operator!=(const MyString &s)
{
	return (!(*this == s));

}

//toan tu so sanh >
bool MyString::operator>(const MyString &s)
{
	if (this->n > s.n)
	{
		for (int i = 0; i < n; i++)
		{
			if (data[i] < s.data[i]) return false;
			break;
			return true;
		}
	}
	else {
		for (int i = 0; i < s.n; i++)
		{
			if (data[i] <= s.data[i]) return false;
			break;
			return true;
		}
	}
}

//toan tu so sanh >=
bool MyString::operator>=(const MyString &s)
{
	if (this->n > s.n)
	{
		for (int i = 0; i < n; i++)
		{
			if (data[i] < s.data[i]) return false;
			break;
			return true;
		}
	}
	else {
		for (int i = 0; i < s.n; i++)
		{
			if (data[i] < s.data[i]) return false;
			break;
			return true;
		}
	}
}

//toan tu so sanh <
bool MyString::operator<(const MyString &s)
{
	return !(*this >= s);
}

//toan tu so sanh <=
bool MyString::operator<=(const MyString &s)
{
	return !(*this > s);
}

//lay ki tu nam trong xau
char MyString::operator[](int i)
{
	return data[i];
}

//in ki tu
void MyString::Xuatkitu(MyString &s)
{
	int kt;
	do
	{
		cout << "\nNhap vao vi tri can lay ki tu " << " tu 0 den " << s.n - 1 << " : ";
		cin >> kt;
		if (kt < 0 || kt > s.n - 1)
		{
			cout << "\nVui long nhap lai!";
		}
		else
		{
			cout << "\nKi tu lay duoc: ";
			if (s.data[kt] == ' ') cout << "\ Day la ki tu khoang trang! " << endl;
			if (s.data[kt] != '\0') cout << s.data[kt] << endl;
		}
	} while (kt < 0 || kt > s.n - 1);
}




MyString::~MyString()
{
	delete[] data;
}

//da nang hoa toan tu xuat
ostream & operator<<(ostream &o, const MyString &s)
{
	for (int i = 0; i <= s.n; i++) {
		if (s.data[i] != '\0')
		{
			o << s.data[i];
		}
	}
	return o;
}

// da nang hoa toan tu nhap
istream & operator>>(istream &i, const MyString &s)
{
	i >> s.data;
	return i;
}

void MyString::Ghivaoxau(MyString &s)
{

	cout << "\nGhi vao mot xau: ";
	cin >> s.data;
	int i = 0;
	char c = '\0';
	while (s[i] != c) {
		i++;
	}
	s.n = i;
	cout << "\nDoc xau vua ghi la: ";
	for (int i = 0; i < s.n; i++)
	{
		cout << s.data[i];
	}
}
