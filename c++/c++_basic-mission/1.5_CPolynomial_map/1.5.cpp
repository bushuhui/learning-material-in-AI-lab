#include"CPolynomial.h"

CPolynomial::CPolynomial()
{
	m_Polynomial.clear();
}

CPolynomial::CPolynomial(string file)
{
	ReadFromFile(file);
}

CPolynomial::~CPolynomial()
{
	m_Polynomial.clear();
}

CPolynomial::CPolynomial(const CPolynomial& poly)
{
	if (this != &poly)
	{
		this->m_Polynomial.clear();
		this->m_Polynomial = poly.m_Polynomial; 
	}
}


CPolynomial CPolynomial::operator+(const CPolynomial& right) 
{
	CPolynomial poly(*this);	
	map<int,double>::iterator iter1;	
	map<int, double> tp1;
	tp1 = right.m_Polynomial;	
	int x; double y;
	for(iter1=tp1.begin();iter1!=tp1.end();iter1++)
	{
		x=iter1->first;    y=iter1->second;
		poly.AddOneTerm(x,y);
	}	
	return poly;
}

CPolynomial CPolynomial::operator-(const CPolynomial& right)
{	

	CPolynomial poly(*this);
	map<int, double> tp1;
	map<int, double> tp2;

	tp1 = right.m_Polynomial;
	map<int,double>::iterator iter1;
	int x; double y;
	for(iter1 = tp1.begin(); iter1 != tp1.end(); iter1++)
	{
		y = -(iter1->second);
		x = iter1->first;
		poly.AddOneTerm(x,y);
	}
	return poly;
}

CPolynomial CPolynomial::operator*(const CPolynomial& right)
{	
	CPolynomial poly(*this);
	CPolynomial poly1;
	map<int, double> tp1;   tp1 = right.m_Polynomial;
	map<int, double> tp2;	tp2 = poly.m_Polynomial;	
	map<int, double>::iterator iter1;   
	map<int, double>::iterator iter2;   
	int x; double y;
	for(iter1 = tp1.begin();iter1!=tp1.end();iter1++)
	{	for(iter2 = tp2.begin();iter2!=tp2.end();iter2++)
		{				
			y = (iter1->second) * (iter2->second);
			x = (iter1->first) + (iter2->first);			
			poly1.AddOneTerm(x,y);
		}
	}
	return poly1;
}

CPolynomial &CPolynomial::operator=(const CPolynomial& right)
{
	if(this != &right)
	{
		this->m_Polynomial.clear();
		this->m_Polynomial = right.m_Polynomial;
	}
	return *this;
}


//觉得用这个太繁琐就没用了  留在这里以后可以参考下
/*
void CPolynomial::MergeSimilarTerms(map<int, double> it1,map<int, double> it2)
{	
	int deg;  double cof;
	double cof1,cof2;
	map<int, double>::iterator iter1;
	map<int, double>::iterator iter2;
	iter1=it1.begin();
	for(;iter1 != it1.end() ;iter1++)
	{	
		deg=iter1->first; 
		cof=iter1->second;

		iter2 = it2.find(int(deg));
		
		if(iter2 == it2.end())
        {			
			it2[int(deg)]=cof;			
		}
		if(iter2 != it2.end())
		{
			cof1=cof;
			cof2=iter2->second;
			it2.erase(iter2);
			if((cof1 + cof2)!=0)
			{it2[int(deg)]= cof1 + cof2 ;}			
		}
	
	}
	m_Polynomial=it2;	
	
}
*/

void CPolynomial::ReadFromFile(string file)
{
	ifstream inp;
    inp.open(file.c_str());
	if(!inp)
	{
		std::cout<<"failed"<<std::endl;
	}
	char ch;
	int n;
	inp >> ch; 
	inp >> n;
	int deg;double cof;
	for (int i=0; i<n; i++)
	{	
		inp>>deg; 
		inp>>cof;		
	 AddOneTerm (deg,cof);			
	}
	inp.close();
}

void CPolynomial::AddOneTerm(int x,double y)
{
		int deg; double cof,cof1,cof2;
		deg = x; cof = y;
		map<int,double>::iterator iter1;
		iter1 = m_Polynomial.find(int(deg));		
		if(iter1 == m_Polynomial.end())
        {
			
			m_Polynomial[int(deg)]=cof;
			
		}
		if(iter1 != m_Polynomial.end())
		{
			cof1=cof;
			cof2=iter1->second;
			m_Polynomial.erase(iter1);
			if((cof1 + cof2)!=0)
			{
				m_Polynomial[int(deg)]= cof1 + cof2 ;
			}	
		}
}

void CPolynomial::Print()
{
	map<int,double>::iterator it;
	std::cout << "The polynomial is:" <<std::endl;
	for (it = m_Polynomial.begin(); it != m_Polynomial.end(); it++)
	{		
        if (it != m_Polynomial.begin())
        {
			if (it->second>0)
			{
				std::cout << "+";
			}
		}
		std::cout << it->second << " ";       
		if (it->first != 0)
        {
			std::cout << "x^" << it->first;
        }
		std::cout << " ";
	}
	std::cout<<endl;
}

