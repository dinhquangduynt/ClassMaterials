/*
#include "queue.h"

queue::queue()
{
}

queue::~queue()
{
}
int Succ(int k) 
{
	return (k + 1) % nMax;
 }
int queue::Empty() 
{ 
	return (first == -1 && last == -1) ? 1 : 0;
}
int queue::Overflow() 
{ 
	return Succ(first) == last ? 1 : 0; 
}
int queue::Delete()
{
	int p = Info[last]; last = Succ(last);
	if (Succ(first) == last) first = last = -1;
	return p;
}
void queue::Add(int x)
{
	if (Empty()) { 
		first = last = 0; 
	}
	else first = Succ(first);
	Info[first] = x;
}

void queue::List()
{
	int k = last;
	while (!Empty()) cout << setw(8) << Delete();
	cout << endl;
	last = k;
}
void queue::Create()
{
	int x;
	cout << "De ket thuc, nhap 0" << endl;
	do {
		cout << "New value: ";
		cin >> x;
		if (!Overflow() && x != 0) Add(x);
	} while (!Overflow() && x != 0);
}*/
#include "queue.h"
queue::queue()
{
	rear = -1;
	front = 0;
	data = new CongTrinhKhoaHoc *[size];
}


queue::~queue()
{
	delete[]data;
}

int queue::getRear()
{
	return this->rear;
}

bool queue::isEmpty()
{
	if (rear == -1)
		return true;
	return false;
}

bool queue::isFull()
{
	if (rear == size)
		return true;
	return false;
}

bool queue::Push(CongTrinhKhoaHoc *ct)
{
	if (isFull())
		return false;
	rear++;
	data[rear] = ct;
	return true;
	cout << "push" << endl;
}

bool queue::Pop(CongTrinhKhoaHoc *(&ct))
{
	if (isEmpty() || front > rear)
		return false;
	ct=data[front];
	front++;
	return true;
}

bool queue::Top(CongTrinhKhoaHoc *(&ct))
{
	if (isEmpty() || front > rear)
		return false;
	ct = data[front];
	return true;
}
