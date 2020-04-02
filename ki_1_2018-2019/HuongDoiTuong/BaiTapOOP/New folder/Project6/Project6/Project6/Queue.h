#pragma once
#include"NhanVien.h"
class Queue
{
private:
	int front; //bien luu vi tri dau hang doi mac dinh = 0 
	int rear; // bien luu vi tri cuoi hang doi mac dinh = 1
	NhanVien **data; // du lieu hang doi
	int size = 100;// kich thuoc hang doi . neu ko khoi tao hoac khoi tao sai thi mac dinh la 10
public:
	Queue();
	~Queue();
	int getRear();
	bool isEmpty();// kiem tra hang doi co rong ko 
	bool isFull();// kiem tra hang doi co day ko
	bool Push(NhanVien *nv); // them gia tri vao hang doi , neu them cong thi tra ve true , ko thi tra ve false
	bool Pop(NhanVien *(&nv)); // lay gia tri ra hang doi va xoa gia tri do di
	bool Top(NhanVien *(&nv));
};
