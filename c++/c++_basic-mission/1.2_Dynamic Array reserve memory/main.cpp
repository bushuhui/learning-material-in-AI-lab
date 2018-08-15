#include<iostream>
using namespace std;
#include"1.2м╥нд╪Ч.h"


int main()
{
	CDArray a;
	a.InsertAt(0, 2.1);
	a.Print();
	
	a.Pushback(3.0);
	a.Pushback(3.1);
	a.Pushback(3.2);
	a.Pushback(3.3);
	a.Pushback(3.5);
	a.Pushback(3.6);
	a.Pushback(3.7);	

	a.Print();
	return 0;
}