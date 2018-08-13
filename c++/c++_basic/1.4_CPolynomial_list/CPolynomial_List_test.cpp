#include "CPolynomial_List.h"

int main()
{
    // FIXME: please put P3.txt, P4.txt in the folder,
    //  thus it can be easy to test the program
 	CPolynomial p1("P3.txt");
 	CPolynomial p2("P4.txt");
 	CPolynomial p3;
 	p1.Print();
 	p2.Print();
 
 	p3 = p1+p2;
 	p3.Print();

 	p3 = p1-p2;
 	p3.Print();
 
 	p3 = p1*p2;
 	p3.Print();

	return 0;
}
