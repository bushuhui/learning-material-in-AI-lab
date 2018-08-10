#ifndef __CPOLYNOMIAL_LIST_H__
#define __CPOLYNOMIAL_LIST_H__

#include <iostream>
#include <list>
#include <vector>
#include <cstring>
#include <fstream>

// FIXME: do not use namespace in header file
using namespace std;

typedef struct Node
{
    double  cof;      // coefficient 
	int     deg;      // degree
} Node;               // the node of polynomial

class CPolynomial  
{
private:
    list<Node> m_Polynomial;	

public:
	CPolynomial();
	CPolynomial(string file);										// initialization using file
	
	CPolynomial(double *cof, int *deg, int n);
	CPolynomial(vector<double> cof, vector<int> deg);
    CPolynomial(const CPolynomial& poly);
	virtual ~CPolynomial();

    
	CPolynomial operator+(const CPolynomial& right);		
	CPolynomial operator-(const CPolynomial& right);		
	CPolynomial operator*(const CPolynomial& right);	
	CPolynomial& operator=(const CPolynomial& right);				
	
	void Print();

private:
	void ReadFromFile(string file);  
    void AddOneTerm(Node term);					// add one term into m_Polynomial
	
};

#endif // end of __CPOLYNOMIAL_LIST_H__

