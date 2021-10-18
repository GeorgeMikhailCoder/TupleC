// task9.cpp : Defines the entry point for the application.
//

#include "task9.h"



int main()
{

	TupleType<2, float, int, string> a(0.1,5,"asd");
	a.single = 0.1;
	a.difficult.single = 7;
	a.difficult.difficult.single = "qwe";
	void * x = a[1];
	cout << *((int*)x) << endl;
	system("pause");
	return 0;
}
