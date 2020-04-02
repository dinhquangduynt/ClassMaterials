#include"MyString.h"

int main() {
	int luachon, lc, kt;
	MyString  a("DAI HOC "), b("BACH KHOA"), c("DA NANG"), h("DAI HOC BACH KHOA DA NANG");
	MyString d(c), g, f;
	do
	{
		cout << "\n\n\t\t\t\t\t" << "==================MENU==================" << endl;
		cout << "\t\t\t\t\t" << "========================================" << endl;
		cout << "\t\t\t\t\t" << "=====1. Copy constructor================" << endl;
		cout << "\t\t\t\t\t" << "=====2. Noi xau=========================" << endl;
		cout << "\t\t\t\t\t" << "=====3. Gan xau=========================" << endl;
		cout << "\t\t\t\t\t" << "=====4. So sanh xau=====================" << endl;
		cout << "\t\t\t\t\t" << "=====5. So sanh theo thu tu tu dien=====" << endl;
		cout << "\t\t\t\t\t" << "=====6. Lay ki tu xau===================" << endl;
		cout << "\t\t\t\t\t" << "=====7. Doc xau=========================" << endl;
		cout << "\t\t\t\t\t" << "=====8. Ghi xau=========================" << endl;
		cout << "\t\t\t\t\t" << "=====0. Thoat===========================" << endl;
		cout << "\tNhap lua chon cua ban: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			cout << "\nCopy tu xau " << c << " duoc xau: ";
			cout << d;
			break;
		case 2:
			cout << "\nXau sau khi noi tu xau  " << a << " +  " << b << " la:  " << (a + b) << endl;
			//cout <<"\nXau sau khi noi tu xau " << a << " & " << b << " la:  " << (a & b);
			break;
		case 3:
			cout << "\nXau f ban dau: " << f;
			cout << "\nKet qua sau khi gan xau " << b << " vao xau f la: ";
			cout << (f = b);
			break;
		case 4:
			cout << "\nKet qua so sanh hai xau la:  ";
			if (a == b) cout << "Hai xau bang hau!" << endl;
			else cout << "Hai xau khac nhau!" << endl;
			break;

		case 5:
			cout << "\nSo sanh theo thu tu tu dien cua hai xau " << a << "va " << b << " la: " << endl;
			if (a > b) cout << "xau " << a << " lon hon xau " << b << endl;
			if (a >= b) cout << "xau " << a << " hon hoac bang xau " << b << endl;
			if (a < b) cout << "xau " << a << " nho hon xau " << b << endl;
			if (a <= b) cout << "Xau " << a << " nho hon hoac bang xau " << b << endl;

			cout << "\nSo sanh theo thu tu tu dien cua hai xau " << b << "va " << a << " la: " << endl;
			if (b > a) cout << "xau " << b << " lon hon xau " << a << endl;
			if (b >= a) cout << "xau " << b << " lon hon hoac bang xau " << a << endl;
			if (b < a) cout << "xau " << b << " nho hon xau " << a << endl;
			if (b <= a) cout << "Xau " << b << " nho hon hoac bang xau " << a << endl;
			break;
		case 6:
			cout << "\nLay ki tu cua xau " << a << endl;
			g.Xuatkitu(a);
			break;
		case 7:
			cout << "\nDoc xau a: " << a << endl;
			cout << "\nDoc xau b: " << b << endl;
			cout << "\nDoc xau c: " << c << endl;
			break;
		case 8:
			g.Ghivaoxau(h);
			break;
		}
	} while (luachon != 0);
	system("pause");
	return 0;
}