#ifndef _CDARRAY_H_
#define _CDARRAY_H_

#include<iostream>
#define SAFEDELETES(p)   if(p) {delete [] p; p=NULL;}
#define SAFEJUDGEMENT(p)  if(p==NULL) {cout<<"no ehough memory"<<endl; return 0;}

class CDArray
{	
	public:
	 CDArray();            
	 CDArray(int nSize, double dValue);  
	 ~CDArray();       
     CDArray(CDArray const &arr);
	 void  	   Print();             
	int        GetSize();          
	int        SetSize(int nSize);  
	int	DeleteAt(int nIndex);			
	double GetAt (int nIndex);					
	
	int InsertAt(int nIndex, double dValue);	
	int SetAt (int nIndex, double dValue);     
	int Pushback(double dValue);
	CDArray& CDArray::operator = (const CDArray& array);
	
private:
	void    Init();        
	void    Free();        
	inline    int    InvalidateIndex(int nIndex)
	{	if (nIndex<0||nIndex> m_nSize)
		{
			return 0;
		}
			else
		{
			return 1;
		}
	}
private:
	double    *m_pData;    
	int        m_nSize; 
	int        m_nMax;	
};

#endif