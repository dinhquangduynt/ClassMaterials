#include "LopSinhHoat.h"
#include "Node.h"



LopSinhHoat::LopSinhHoat()
{
	this->tenlopsinhhoat = "";
	this->head = NULL;
	this->tail = NULL;
	this->lecturer = Lecturer();
	this->sisosv = 0;
}


LopSinhHoat::~LopSinhHoat()
{
}

void LopSinhHoat::chendau(Node * n)
{
	if (head == NULL)
	{
		head = tail = n;
		head->setnext(tail);
		tail->setnext(head);
	}
	else
	{
		n->setnext(head);
		tail->setnext(n);
		head = n;
	}
	sisosv++;
}

void LopSinhHoat::chencuoi(Node * n)
{
	if (head == NULL)
	{
		head = tail = n;
		head->setnext(tail);
		tail->setnext(head);
	}
	else
	{
		n->setnext(head);
		tail->setnext(n);
		tail = n;
	}
	sisosv++;
}

void LopSinhHoat::chenbatky(int k, Node * n)
{
	if (head == NULL)
	{
		head = tail = n;
		head->setnext(tail);
		tail->setnext(head);
		sisosv++;
	}
	else
	{
		if (k == 0) chendau(n);
		else
		{
			if (k == sisosv) chencuoi(n);
			else
			{
				if (k > 0 && k < sisosv)
				{
					Node *tam = head;
					int i = 0;
					while (i != k - 1)
					{
						tam = tam->getnext();
						i++;
					}
					tam->setnext(n);
					n->setnext(tam->getnext());
					sisosv++;
				}
				else cout << "Vi tri k khong hop le!";
			}
		}
	}
}

void LopSinhHoat::capnhat(int k)
{
	if (k<0 || k>sisosv - 1) cout << "khong ton tai node!";
	else
	{
		xoa(k);
		cout << "Nhao thong tin node muon cap nhat" << endl;
		Node *n = new Node();
		n->Nhap();
		chenbatky(k,n);
	}
}

void LopSinhHoat::xoa(int k)
{
	if (k == 0)
	{
		head=head->getnext();
		sisosv--;
	}
	else
	{
		if (k > 0 && k <= sisosv - 1)
		{
			Node *tam = head;
			int i = 0;
			while (i != k - 1)
			{
				tam = tam->getnext();
				i++;
			}
			tam->setnext((tam->getnext())->getnext());
			sisosv--;
		}
		else cout << "Khong ton tai node!";
	}
}

void LopSinhHoat::timkiem()
{
	//Node *kt = this->head;
	Node *kt = new Node();
	kt = this->head;
	/*int x;
	cout << "Nhap diem trung binh can tim:";
	cin >> x;
	cout << x;
	while (kt->getnext() !=NULL && kt->getdata().getdiemtb() != x)
	{
		kt = kt->getnext();
	}
	if(kt!=NULL) kt->Xuat();
	else cout << "khong co ket qua"<<endl;*/
	string x = "";
	cin.ignore();
	cout << "nhap ten muon tim:";
	getline(std::cin, x);
	while (kt->getnext() != NULL && kt->getdata().getten() != x)
	{
		kt = kt->getnext();
	}
	if (kt != NULL) kt->Xuat();
	else cout << "khong co ket qua" << endl;
}

Lecturer LopSinhHoat::getlecturer()
{
	return this->lecturer;
}

void LopSinhHoat::xuatlec()
{
	
}




istream & operator>>(istream & i, LopSinhHoat & l)
{

	cout << "\t" << "*Moi Nhap Ten Lop:  ";
	getline(std::cin, l.tenlopsinhhoat);
	cout << " -------- Nhap thong tin giao vien ---------\n";
	l.lecturer.Nhap();
	cout << " -------- Nhap thong tin sinh vien ---------\n";
	int sluong;
	cout << "Nhap so luong sinh vien:";
	cin >> sluong;
	for (int n = 0; n < sluong; n++)
	{
		Node *node = new Node();
		node->Nhap();		
		l.chencuoi(node);
	}
	return i;
}

ostream & operator<<(ostream & o, LopSinhHoat & l)
{
	o <<"Lop:"<< l.tenlopsinhhoat << endl;
	o << "----thong tin giao vien----"<<endl;
	l.lecturer.Xuat();
	Node *tam = new Node();
	tam = l.head;
	o << "----thong tin sinh vien----"<<endl;
	for (int i = 0; i < l.sisosv; i++)
	{
		cout << endl;
		tam->Xuat();
		tam = tam->getnext();
	}
	return o;
}
