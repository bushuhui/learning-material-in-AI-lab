#include<iostream>
#include<map>
#include <cstring>
#include <fstream>
using namespace std;



class CPolynomial  
{
private:
	map<int, double> m_Polynomial;
public:
	CPolynomial();
	CPolynomial(string file);										// initialization using file
	CPolynomial::CPolynomial(const CPolynomial& poly);
	virtual ~CPolynomial();

    
	CPolynomial operator+(const CPolynomial& right) ;		
	CPolynomial operator-(const CPolynomial& right);		
	CPolynomial operator*(const CPolynomial& right);	
	CPolynomial& operator=(const CPolynomial& right);				
	
	void Print();

private:
	void ReadFromFile(string file);  
	//void MergeSimilarTerms(map<int, double> it1,map<int, double> it2);
	void AddOneTerm(int x,double y);

};
