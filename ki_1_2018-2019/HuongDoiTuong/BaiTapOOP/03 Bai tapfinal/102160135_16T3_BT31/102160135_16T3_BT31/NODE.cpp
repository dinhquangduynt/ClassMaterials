#include "NODE.h"


NhanVien * NODE::getData()
{
	return data;
}

NODE * NODE::getNext()
{
	return next;
}

NODE * NODE::getPrev()
{
	return prev;
}

void NODE::setData(NhanVien *nv)
{
	data = nv;
}

void NODE::setNext(NODE *Next)
{
	next = Next;
}

void NODE::setPrev(NODE *Prev)
{
	prev = Prev;
}

NODE::NODE()
{
}


NODE::~NODE()
{
}
