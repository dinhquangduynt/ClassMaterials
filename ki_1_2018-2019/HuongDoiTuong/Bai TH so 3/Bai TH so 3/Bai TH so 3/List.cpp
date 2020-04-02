#include "List.h"



List::List()
{
}


List::~List()
{
	while (this->p->pNext != NULL)
	{
		NODE* temp = this->p;
		p = p->pNext;
		delete temp;
	}
	
}

void List::Init()
{
	this->p = NULL;
}

NODE * List::CreateNode(SinhVien data)
{
	NODE *q = new NODE;
	if (q == NULL) {
		cout << ("khong du bo nho");
		return NULL;
	}
	q->data = data;
	q->pNext = NULL;
	return q;
}

void List::AddHead(NODE *q)
{
	if (this->p == NULL)
	{
		this->p = q;
	}
	else
	{
		q->pNext = this->p;
		this->p = q;
	}
}


void List::AddTail(NODE *q)
{
	if (this->p == NULL)
	{
		this->p = q;
	}
	else
	{
		NODE *temp;
		temp = this->p;
		while (temp->pNext != NULL)
		{
			temp = temp->pNext;
		}
		temp->pNext = q;
	}
}

void List::Input()
{
	int n;
	cout << "nhap vao so node: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		SinhVien data;
		cout << "nhap data: " << endl;
		cin >> data;
		NODE *q = CreateNode(data);
		AddTail(q);
	}
}

void List::Output()
{
	NODE *temp;
	temp = this->p;
	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->pNext;
	}
}

void List::Insert()
{
	SinhVien data;
	cout << "nhap data: " << endl;
	cin >> data;
	NODE *q = CreateNode(data);
	int luachon;
	cout << "|--------------Menu---------------|" << endl;
	cout << "| 1. Them Dau                     | " << endl;
	cout << "| 2. Them Cuoi                    |" << endl;
	cout << "| 3. Them vao vi tri i bat ki     |" << endl;
	cout << "|---------------------------------|" << endl;
	cout << "Nhap lua chon: ";
	cin >> luachon;
	if (luachon == 1) {
		AddHead(q);
	}
	else if (luachon == 2) {
		AddTail(q);
	}
	else {
		int i, count = 0;
		cout << "Nhap vao vi tri i: ";
		cin >> i;
		if (i == 0) {
			AddHead(q);
		}
		else 
		{
			for (NODE* k = this->p; k != NULL; k = k->pNext) {
				if (count == i - 1) {
					NODE *temp = k->pNext;
					k->pNext = q;
					q->pNext = temp;
					break;
				}
				count++;
			}
		}
	}
}

void List::Delete()
{
	int luachon;
	cout << "|--------------Menu---------------|" << endl;
	cout << "| 1. Xoa Dau                      | " << endl;
	cout << "| 2. Xoa Cuoi                     |" << endl;
	cout << "| 3. Xoa vi tri i bat ki          |" << endl;
	cout << "|---------------------------------|" << endl;
	cout << "Nhap lua chon: ";
	cin >> luachon;
	if (luachon == 1) {
		NODE*temp = this->p;
		this->p = this->p->pNext;
		delete temp;
	}
	else if(luachon == 2) {
		NODE *temp;
		temp = this->p;
		while (temp->pNext != NULL)
		{
			temp = temp->pNext;
		}
		temp = NULL;
	}
	else
	{
		int i, count = 0;
		cout << "Nhap vao vi tri i: ";
		cin >> i;
		for (NODE* k = this->p; k != NULL; k = k->pNext) {
			if (count == i - 1) {
				NODE *temp = k->pNext;
				k->pNext = temp->pNext;
				delete temp;
				break;
			}
			count++;
		}
	}
}

void List::Search()
{
	string mssv;
	cout << "Nhap Vao MSSV can tim kiem: ";
	cin >> mssv;
	NODE *temp;
	temp = this->p;
	while (temp != NULL)
	{
		if (temp->data.MSSV.compare(mssv) == 0) {
			cout << temp->data;
		}
		temp = temp->pNext;
	}
}
