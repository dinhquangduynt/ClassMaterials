#include "NhanVien.h"
#include "NVBC.h"
#include "NVHD.h"
#pragma once
class NODE
{
public:
	NhanVien data;
	NVBC nvbc;
	NVHD nvhd;
	NODE *next;
	NODE *prev;
public:
	NODE();
	~NODE();
};

