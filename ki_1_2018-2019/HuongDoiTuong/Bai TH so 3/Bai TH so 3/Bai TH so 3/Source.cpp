#include<iostream>
#include"List.h"
using namespace std;

int main() {
	List l;
	l.Init();
	l.Input();
	l.Output();
	l.Insert();
	l.Output();
	l.Delete();
	l.Output();
	l.Search();
	system("pause");
	return 0;
}