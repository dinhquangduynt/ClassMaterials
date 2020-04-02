#include "QLNV.h"



QLNV::QLNV()
{
}


QLNV::~QLNV()
{
}


//void QLNV::operator=(const QLNV nv)
//{
//	TQL = nv.TQL;
//	n = nv.n;
//}

NODE * QLNV::CreateNode(NhanVien nv)
{
	NODE *node = new NODE;
	if (node == NULL) {
		return NULL;
	}
	node->data = nv;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void QLNV::Init()
{
	this->head = NULL;
	this->tail = NULL;
}

bool QLNV::IsEmpty(QLNV &list)
{
	if (list.head == NULL && list.tail == NULL)
		return true;
	return false;
}

void QLNV::Addhead(QLNV &l, NhanVien nv)
{
	NODE *node = CreateNode(nv);
	if (IsEmpty(l))
	{
		l.head = l.tail = node;
		node->next = node->prev = l.head;// khep vong
		n++;
	}
	else
	{
		l.head->prev = node->next; // khep vong
		node->next = l.head;
		l.head->prev = node;
		l.head = node;
		n++;

	}

}

void QLNV::Addtail(QLNV &l, NhanVien nv)
{
	NODE *node = CreateNode(nv);
	if (IsEmpty(l))
	{
		l.tail = l.head = node;
		node->next = node->prev = l.head;// khep vong
		n++;
	}
	else
	{
		l.tail->next = node->prev;
		l.tail->next = node; // tro toi
		node->prev = l.tail; // tro lui
		l.tail = node; //gan lai node
		n++;
	}

}

void QLNV::Add(QLNV &l, NhanVien nv)
{
	int k, dem = 1;
	cout << "\nNhap vao vi tri can them: ";
	cin >> k;
	if (IsEmpty(l) || k <= 1)
	{
		Addhead(l, nv);
		n++;
	}
	else if (k > n) { Addtail(l, nv); }
	else
	{

		NODE *node = CreateNode(nv);
		NODE *temp = new NODE;
		NODE *h = l.head;
		while (h != NULL)
		{
			if (dem = k - 1) {
				temp = h->next; temp->prev = node;
				node->next = temp; node->prev = h;
				h->next = node;
				n++;
				break;
			}
			dem++;
			h = h->next;
		}
	}

}

void QLNV::Nhap(QLNV &l)
{
	cout << "\nNhap vao so nhan vien can tao: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		NhanVien data;
		cout << "Nhap nhan vien thu " << i + 1 << " ";
		cin >> data;
		NODE *node = CreateNode(data);
		Addtail(l, data);
		Addhead(l, data);
	}
}

void QLNV::Xuat(QLNV &l)
{
	int i = 1;
	if (IsEmpty(l)) cout << "\nKhong co du lieu" << endl;
	else
	{
		NODE *h = l.head;
		cout << "\nDanh sach nhan vien" << endl;
		do
		{
			cout << "\nNhan vien thu " << i << ":\n";
			cout << h->data;
			h = h->next;
			i++;
		} while (h != l.tail->next);
	}
}

void QLNV::Deletehead(QLNV &l)
{
	if (l.head != l.tail)
	{
		NODE *p = l.head;
		l.head = l.head->next;
		l.head->prev = l.tail;
		delete p;
		l.tail->next = l.head;
	}
	else
	{
		l.head = l.tail = NULL;
	}

}

void QLNV::Deletetail(QLNV &l)
{
	/*if (IsEmpty(l)) return;
	else
	{*/
	if (l.head != l.tail)
	{
		NODE *p = l.tail;
		l.tail = l.tail->prev;
		l.tail->next = l.head;
		delete p;
		l.head->prev = l.tail;
		//l.tail->next = l.head->prev;
	}
	else
	{
		l.head = l.tail = NULL;
	}
	//}
}

//loi
void QLNV::Delete(QLNV &l)
{
	int k, dem = 1;
	cout << "\nNhap vao vi tri can xoa: ";
	cin >> k;
	if (k <= 1) Deletehead(l);
	else if (k >= n) Deletetail(l);
	else
	{
		NODE *p = l.head;
		NODE *temp = new NODE;
		do
		{
			if (dem == k - 1)
			{
				temp = p->next;
				p->next = temp->next;
				p = (temp->next)->prev;
				delete temp;
				break;
			}
			dem++;
			p = p->next;
		} while (p != temp->next);
	}

}


void QLNV::Search(NhanVien &nv, string msnv)
{
	string ms;
	int i = 1;
	cin.ignore();
	do
	{
		cout << "\nNhap ma so nhan vien: ";
		getline(cin, ms);
		if (ms.length() != 8)
			cout << "\nMa so nhan vien khong hop le!";
	} while (ms.length() != 8);

	NODE *p = this->head;
	if (this->head)
	{
		do
		{

			if (p->data.getMaso() == ms)
			{
				cout << "\nNhan vien thu " << i;
				cout << p->data;
				i++;
			}
			p = p->next;
		} while (p != (this->tail)->next);
	}
	else
	{
		cout << "\nKhong co du lieu";
	}

}

void QLNV::Update(QLNV &l)
{
	int fix;
	NhanVien *nv;
	string ms, ms1, ht;
	bool gt;
	double lg; int n, t, nm;
	Date d;
	if (IsEmpty(l)) cout << "\nKhong co du lieu!";
	else
	{
		NODE *p = l.head;
		cin.ignore();
		do
		{
			cout << "\Nhap MSNV can cap nhat: ";
			getline(cin, ms);
			if (ms.length() != 8)
				cout << "\nMa so khong hop le!";

		} while (ms.length() != 8);

		do
		{
			if (ms.compare((p->data).getMaso()) == 0)
			{
				do
				{
					cout << "\n\t\t\tNhap 1 neu muon cap nhat lai ma so nhan vien!";
					cout << "\n\t\t\tNhap 2 neu muon cap nhat lai ten nhan vien!";
					cout << "\n\t\t\tNhap 3 neu muon cap nhat lai gioi tinh nhan vien!";
					cout << "\n\t\t\tNhap 0 neu muon da cap nhat xong!";
					cout << "\nMoi nhap lua chon: ";
					cin >> fix;
					switch (fix)
					{
					case 1:
						cin.ignore();
						cout << "\nNhap ma so nhan vien: ";
						getline(cin, ms1);
						p->data.setMaso(ms1);
						break;
					case 2:
						cin.ignore();
						cout << "\nNhap ten nhan vien muon cap nhat: ";
						getline(cin, ht);
						p->data.setTen(ht);
						break;
					case 3:
						cout << "\nNhap gioi tinh muon cap nhat: ";
						cin >> gt;
						p->data.setGioitinh(gt);
						break;
					}
				} while (fix != 0);
			}
			p = p->next;
		} while (p != l.tail->next);

	}
}

//hoan vi
void swap(NhanVien &x, NhanVien &y) {
	NhanVien temp = x; x = y; y = temp;
}
//tang dan
bool TD(string left, string rigth) {
	if (left > rigth)
		return true;
	return false;
}

//giam dan
bool GD(string left, string rigth) {
	if (left < rigth)
		return true;
	return false;
}

//NODE *QLNV::mid(QLNV l) {
//	if (IsEmpty(l)) return 0 ;
//	else
//	{
//		NODE *p = l.head;
//		NODE *q = l.head;
//		while (q->next && q->next->next !=l.head)
//		{
//			p=p->next;
//			q=q->next->next;
//		}
//		return p;
//	}
//
//}

//void QLNV::shellsort(bool(*q)(string, string))
//{
//	QLNV l;
//	NODE *p;
//	NODE *k;
//	for (p = mid(l); p != l.head; p = p->prev->prev)
//	{
//		for (k = l.head; k != mid(l); k = k->next)
//		{
//			//int j = i;
//			do
//			{
//				if (q(p->data.getMaso(), k->data.getMaso()))
//				{
//					swap(p->data, k->data);
//				}
//				//j = j - h;
//			} while (q(p->data.getMaso() , k->data.getMaso()));
//
//		}
//	}
//}

//void QLNV::Sapxep()
//{
//	int lc;
//	cout << "\nBan muon sap xep nhu the nao(1-tang dan, 2 giam dan): ";
//	cin >> lc;
//	if (lc == 1)
//	{
//		shellsort(TD);
//	}
//	if (lc == 2)
//	{
//		shellsort(GD);
//	}
//}


ostream & operator<<(ostream &o, const QLNV &l)
{
	int i = 1;
	if (l.head)
	{

		NODE *h = l.head;
		cout << "\nDanh sach nhan vien" << endl;

		do
		{
			cout << "\nNhan vien thu " << i << ":\n";
			cout << h->data;
			h = h->next;
			i++;
		} while (h != l.tail->next);
	}
	else
	{
		return o << "\nKhong co du lieu";
	}
	return o;
}

istream & operator>>(istream &i, QLNV &l)
{
	int n;
	cout << "\nNhap vao so nhan vien can tao: ";
	i >> n;
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		NhanVien data;
		cout << "Nhap nhan vien thu " << i + 1 << " ";
		cin >> data;
		NODE *node = l.CreateNode(data);
		l.Addtail(l, data);
		//Addhead(l, data);
	}
	return i;
}
