
#pragma once
#include"CongTrinhKhoaHoc.h"
class queue
{
private:
	int front; //bien luu vi tri dau hang doi mac dinh = 0 
	int rear; // bien luu vi tri cuoi hang doi mac dinh = 1
	CongTrinhKhoaHoc **data; // du lieu hang doi
	int size = 100;// kich thuoc hang doi . neu ko khoi tao hoac khoi tao sai thi mac dinh la 10
public:
	queue();
	~queue();
	int getRear();
	bool isEmpty();// kiem tra hang doi co rong ko 
	bool isFull();// kiem tra hang doi co day ko
	bool Push(CongTrinhKhoaHoc *ct); // them gia tri vao hang doi , neu them cong thi tra ve true , ko thi tra ve false
	bool Pop(CongTrinhKhoaHoc *(&ct)); // lay gia tri ra hang doi va xoa gia tri do di
	bool Top(CongTrinhKhoaHoc *(&ct));//lay gia tri hang doi nhung k xoa
};


