#include "Queue.h"
Queue::Queue()
{
	rear = -1;
	front = 0;
	data = new NhanVien *[size];
}


Queue::~Queue()
{
	delete[]data;
}

int Queue::getRear()
{
	return this->rear;
}

bool Queue::isEmpty()
{
	if (rear == -1)
		return true;
	return false;
}

bool Queue::isFull()
{
	if (rear == size)
		return true;
	return false;
}

bool Queue::Push(NhanVien *nv)
{
	if (isFull())
		return false;
	rear++;
	data[rear] = nv;
	return true;
}

bool Queue::Pop(NhanVien *(&nv))
{
	if (isEmpty() || front > rear)
		return false;
	nv = data[front];
	front++;
	return true;
}

bool Queue::Top(NhanVien *(&nv))
{
	if (isEmpty() || front > rear)
		return false;
	nv = data[front];
	return true;
}
