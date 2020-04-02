#include "NhanVien.h"
#include "NVBC.h"
#include "NVHD.h"
#pragma once
class NODE
{
private:
	NhanVien *data;
	NVBC nvbc;
	NVHD nvhd;
	NODE *next;
	NODE *prev;
public:
	NhanVien *getData();
	NODE *getNext();
	NODE *getPrev();
	void setData(NhanVien *);
	void setNext(NODE*);
	void setPrev(NODE*);
	NODE();
	~NODE();
};

