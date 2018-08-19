#include"CDArray.h" 

int main()
{
	CDArray a;
	a.InsertAt(0, 2.1);
	a.Print();
	
	a.Pushback(3.0);
	a.Pushback(3.1);
	a.Pushback(3.2);
	a.Print();

	a.DeleteAt(0);
	a.Print();
	a.InsertAt(0, 4.1);
	a.Print();
	
	CDArray acopy=a;
	acopy.Print();

	CDArray acopy2(a);
	acopy2.Print();

	CDArray acopy3;
	acopy3=a;
	acopy3.Print();

	CDArray b;
	b.Pushback(21);
	b.Print();
	b.DeleteAt(0);
	b.Print();
	b.Pushback(22);
	b.SetSize( 5 );
	b.Print();

	CDArray  c;
	c.Pushback('a');
	c.Pushback('b');
	c.Pushback('c');
	c.InsertAt(0, 'd');
	c.Print();
	
	return 0;
}
