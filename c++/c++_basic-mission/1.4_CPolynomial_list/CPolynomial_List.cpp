#include "CPolynomial_List.h"


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
	list<Node> tp;
	tp = right.m_Polynomial;
	for(list<Node>::iterator it=tp.begin();it!=tp.end();it++)
	{
		poly.AddOneTerm(*it);
	}
	return poly;
}

CPolynomial CPolynomial::operator-(const CPolynomial& right)
{
	CPolynomial poly(*this);
	list<Node> tp;
	tp = right.m_Polynomial;
	for(list<Node>::iterator it=tp.begin();it!=tp.end();it++)
	{	
		(*it).cof = -(*it).cof;
		poly.AddOneTerm(*it);
	}
	return poly;

}

CPolynomial CPolynomial::operator*(const CPolynomial& right)
{
	CPolynomial poly_1(*this);
	CPolynomial poly_3;
	list<Node> p1 = this->m_Polynomial;
	list<Node> p2 = right.m_Polynomial;
	list<Node> p3 = poly_3.m_Polynomial;

	for(list<Node>::iterator it1=p1.begin();it1!=p1.end();it1++)
	{	for(list<Node>::iterator it2=p2.begin();it2!=p2.end();it2++)
		{
			Node tn1,tn2;	
			tn1 = *it1;
			tn2 = *it2;
			tn1.cof *= tn2.cof;
			tn1.deg += tn2.deg;
			poly_3.AddOneTerm(tn1);
		}
	}
	return poly_3;
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

void CPolynomial::ReadFromFile(string file)
{	
	m_Polynomial.clear();
	ifstream inp;
    inp.open(file.c_str());

	char ch;
	int n;
	inp >> ch; 
	inp >> n;
	for (int i=0; i<n; i++)
	{
		Node nd;
		inp>>nd.deg; 
		inp>>nd.cof;

        AddOneTerm(nd);
	}
	inp.close();
}

// insert one term into the list 
void CPolynomial::AddOneTerm(Node term)  
{
	int n=m_Polynomial.size();
	if (n == 0) 
	{ 
		m_Polynomial.push_back(term); 
		return;
	}

	if (term.cof == 0) 
		return;
	else if (term.deg < 0) 
	{ 
		std::cout<<"Degree can not be negative!"<<std::endl; 
		return; 
	}
    
	// iterator of list
	Node td;
	list<Node>::iterator it;
	for (it = m_Polynomial.begin(); it != m_Polynomial.end(); it++)
	{
		td = *it;
		if (term.deg < td.deg) break;
	}
	
	// add 
	it--;
	td = *it;
	if (term.deg == td.deg)
	{
		(*it).cof += term.cof;
		if ((*it).cof == 0)
		{
			m_Polynomial.erase(it);
		}
		return;
	}
    it++;
    
	// insert
    if (it == m_Polynomial.end())
    {
		m_Polynomial.push_back(term); 
		return;
    }

	m_Polynomial.insert(it,term);
}

// print the polynomial
void CPolynomial::Print()
{
	list<Node>::iterator it;
	std::cout << "The polynomial is:" << std::endl;

	for (it = m_Polynomial.begin(); it != m_Polynomial.end(); it++)
	{
		Node td = *it;
		
        if (it != m_Polynomial.begin())
        {
			if (td.cof>0)
			{
				std::cout << "+";
			}
		}
        std::cout << td.cof << " ";
        
		if (td.deg != 0)
        {
			std::cout << "x^" << td.deg;
        }
		std::cout << " ";
	}

	std::cout << endl;
}








