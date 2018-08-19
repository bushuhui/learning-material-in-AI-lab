#include"sqlist.h"

int main()
{
	Sqlist Sq1;
	Sq1.InitList(6);
	Sq1.Print();
	

	Sq1.Insert(3,0);
	Sq1.Print();

	Sq1.Insert(11,0);

	Sq1.Delete(6);
	Sq1.Print();

	return 0;
}

