#include "QLNV.h"



QLNV::QLNV()
{
}


QLNV::~QLNV()
{
}

NODE * QLNV::CreateNode(NhanVien *nv)
{
	NODE *node = new NODE;
	if (node)
	{
		node->setData(nv);
		node->setNext(NULL);
		node->setPrev(NULL);
	}
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

void QLNV::Addhead(NODE &node)
{
		if (head==NULL)
		{
			head = tail = &node;
			node.setNext(head);
			node.setPrev(head);// khep vong
			n++;
		}
		else
		{
			node.setNext(head);
			head->setPrev(&node);
			tail->setNext(&node);
			node.setPrev(tail);
			head = &node;
			n++;
		}		
}


void QLNV::Addtail(NODE *node)
{
		if (head==NULL)
		{
			tail =head = node;
			node->setNext(head);
			node->setPrev(head);// khep vong
			n++;
		}
		else
		{
			head->setPrev(node);
			node->setNext(head);
			tail->setNext(node); // tro toi
			node->setPrev(tail); // tro lui
			tail = node; //gan lai node
			n++;
		}
		
}

void QLNV::Add(NODE *node)
{
		int k, dem = 1;
		cout << "\nNhap vao vi tri can them: ";
		cin >> k;
		if (head==NULL|| k <= 1)
		{
			Addhead(*node);
		}
		else if (k > n) { Addtail(node); }
		else
		{
			NODE *temp = new NODE;
			NODE *h = head;
			while (h != NULL)
			{
				if (dem = k - 1) {
					temp = h->getNext(); temp->setPrev(node);
					node->setNext(temp); node->setPrev(h);
					h->setNext(node);
					n++;
					break;
				}
				dem++;
				h = h->getNext();
			}
		
		}	
}

//void QLNV::Nhap()
//{
//	cin.ignore();
//	cout << "\nNhap ten ca nhan: ";
//	getline(cin, TQL);
//	int lc,m;
//	cout << "\nNhap vao so nhan vien can tao: ";
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		cout << "Nhap nhan vien thu " << i + 1 << " ";
//		do
//		{
//			cout << "\n\t\t\t\t\t" << "=====1. Nhap NVHD====" << endl;
//			cout << "\t\t\t\t\t" << "=====2. Nhap NVBC====" << endl;
//			cout << "\nNhap lua chon cua ban: ";
//			cin >> lc;
//			if (lc != 1 && lc != 2)
//			{
//				cout << "\nVui long nhap lai";
//			}
//			
//		} while (lc != 2 && lc != 1);
//
//		if (lc == 1)
//		{
//			cout << "\nBan dang them nhan vien hop dong";
//			NhanVien *nv = new NVHD;
//			nv->Nhap();
//			NODE *node = CreateNode(nv);
//			Addtail(node);
//		}
//
//		if (lc == 2) {
//			cout << "\nBan dang them nhan vien bien che";
//			NhanVien *nv = new NVBC;
//			nv->Nhap();
//			NODE *node = CreateNode(nv);
//			Addtail(node);
//		}
//	}
//}
//
//void QLNV::Xuat()
//{
//	int i = 1;	
//	NODE *h = this->head; 
//	NhanVien *nv = NULL;
//	cout << "\nTen ca nhan: " << TQL;
//	cout << "\nSo luong nhan vien: " << n;
//	cout << "\nDanh sach nhan vien" << endl;
//	do
//	{
//		cout << "\nNhan vien thu " << i << ":\n";
//		nv = h->getData();
//		nv->Xuat();
//		h = h->getNext();
//		i++;
//	} while (h!= this->tail->getNext());
//
//}

void QLNV::Deletehead()
{
		if (this->head != this->tail)
		{
			NODE *p = this->head;
			this->head = this->head->getNext();
			this->head->setPrev(this->tail);
			delete p;
			this->tail->setNext(this->head);
			n--;
		}
		else
		{
			this->head = this->tail = NULL;
			n--;
		}

}
 
void QLNV::Deletetail()
{
	if (this->head != this->tail)
	{
		NODE *p = this->tail;
		this->tail = this->tail->getPrev();
		this->tail->setNext(this->head);
		delete p;
		this->head->setPrev(this->tail);
		n--;
	}
	else
	{
		this->head = this->tail = NULL;
		n--;
	}
}

void QLNV::Delete()
{
	int k, dem = 1;
	cout << "\nNhap vao vi tri can xoa: ";
	cin >> k;
	if (k <= 1) Deletehead();
	else if (k >= n) Deletetail();
	else
	{
		NODE *p = this->head;
		NODE *temp = new NODE;
		do
		{
			if (dem == k-1)
			{
				temp = p->getNext();
				p->setNext(temp->getNext());
				p=(temp->getNext())->getPrev();
				//temp->getNext.setPrev(p);
				delete temp;
				n--;
				break;
			}
			dem++;
			p = p->getNext();
		} while (p != tail->getNext());
	}

}

void QLNV::Search()
{
	string ms;
	int i = 1;
	cin.ignore();
	cout << "\nNhap ma so nhan vien: ";
	getline(cin,ms);
	NODE *p = this->head;
	NhanVien *nv = NULL;
	if (this->head)
	{
		do
		{

			if (p->getData()->getMaso() == ms)
			{
				cout << "\nNhan vien thu " << i;
				nv = p->getData();
				nv->Xuat();
				i++;
			}
			p = p->getNext();
		} while (p != (this->tail)->getNext());
		if (p == this->tail->getNext() && p->getData()->getMaso() != ms)
		{
			cout << "\nKhong co du lieu";
		}
	}
	else
	{
		cout << "\nKhong co du lieu";
	}
	
}

void QLNV::Update()
{
	int fix;
	NhanVien *nv;
	string ms,ms1, ht;
	bool gt;
	double lg;
	int n, t, nm;
	Date d;
	//if (IsEmpty(l)) cout << "\nKhong co du lieu!";
	if (this->head==NULL)
	{
		cout << "\nKhong co du lieu!";
	}
	else
	{
		NODE *p = this->head;
		cin.ignore();
		do
		{
			cout << "\Nhap MSNV can cap nhat: ";
			getline(cin, ms);
			if (ms.length() != 8)
				cout << "\nMa so khong hop le!";
			
		} while (ms.length() !=8);

		do
		{
			nv = p->getData();
			//p->getData()->getMaso == ms;
			if (ms.compare((nv->getMaso()))==0)
			{
				
				do
				{
					cout << "\n\t\t\tNhap 1 neu muon cap nhat lai ma so nhan vien!";
					cout << "\n\t\t\tNhap 2 neu muon cap nhat lai ten nhan vien!";
					cout << "\n\t\t\tNhap 3 neu muon cap nhat lai gioi tinh nhan vien!";
					cout << "\n\t\t\tNhap 4 neu muon cap nhat lai ngay vao lam!";
					cout << "\n\t\t\tNhap 0 neu muon da cap nhat xong!";
					cout << "\nMoi nhap lua chon: ";
					cin >> fix;
					switch (fix)
					{
					case 1:
						cin.ignore();
						cout << "\nNhap ma so nhan vien: ";
						getline(cin, ms1);
						nv->setMaso(ms1);
						break;
					case 2:
						cin.ignore();
						cout << "\nNhap ten nhan vien muon cap nhat: ";
						getline(cin, ht);
						nv->setTen(ht);
						break;
					case 3:
						cout << "\nNhap gioi tinh muon cap nhat: ";
						cin >> gt;
						nv->setGioitinh(gt);
						break;

					case 4:
						cout << "\nNhap ngay muon cap nhat: ";
						cin >> n;
						d.setNgay(n);
						cout << "\nNhap thang muon cap nhat: ";
						cin >> t;
						d.setThang(t);
						cout << "\nNhap nam muon cap nhat: ";
						cin >> nm;
						d.setNam(nm);
						nv->setDate(d);
						break;
					}
				} while (fix != 0);
			}
			p = p->getNext();
		} while (p!=this->tail->getNext());

	}
}
NODE QLNV::operator[](int i)
{
	NhanVien *nv = NULL;
	int k = 0;
	NODE *h = head;
	while (h!=tail->getNext())
	{
		if (k == i-1)
		{
			cout << h->getData();
			break;
		}
		k++;
		h=h->getNext();
	}
	return NODE();
}
//
////hoan vi
//void swap(NhanVien &x, NhanVien &y) {
//	NhanVien temp = x; x = y; y = temp;
//}
////tang dan
//bool TD(string left, string rigth) {
//	if (left > rigth)
//		return true;
//	return false;
//}
//
////giam dan
//bool GD(string left, string rigth) {
//	if (left < rigth)
//		return true;
//	return false;
//}

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
		NhanVien *nv = NULL;
		cout << "\nTen ca nhan: " << l.TQL;
		cout << "\nSo luong nhan vien: " << l.n;
		cout << "\nDanh sach nhan vien" << endl;
		do
		{
			cout << "\nNhan vien thu " << i << ":\n";
			nv = h->getData();
			nv->Xuat();
			h = h->getNext();
			i++;
		} while (h != l.tail->getNext());
	}
	else
	{
		return o << "\nKhong co du lieu";
	}
		return o;
}

istream & operator>>(istream &i, QLNV &l)
{
	cin.ignore();
	cout << "\nNhap ten ca nhan: ";
	getline(i, l.TQL);
	int k, m;
	cout << "\nNhap vao so nhan vien can tao: ";
	cin >> m;
	for (int j = 0; j < m;j++)
	{
		cout << "Nhap nhan vien thu " << j + 1 << " ";
		do
		{
			cout << "\n\t\t\t\t\t" << "=====1. Nhap NVHD====" << endl;
			cout << "\t\t\t\t\t" << "=====2. Nhap NVBC====" << endl;
			cout << "\nNhap lua chon cua ban: ";
			i >> k;
			if (k != 1 && k != 2)
			{
				cout << "\nVui long nhap lai";
			}

		} while (k != 2 && k != 1);

		if (k == 1)
		{
			cout << "\nBan dang them nhan vien hop dong";
			NhanVien *nv = new NVHD;
			nv->Nhap();
			NODE *node = l.CreateNode(nv);
			l.Addtail(node);
		
		}

		if (k == 2) {
			cout << "\nBan dang them nhan vien bien che";
			NhanVien *nv = new NVBC;
			nv->Nhap();
			NODE *node = l.CreateNode(nv);
			l.Addtail(node);
		}
	}
	return i;
}
