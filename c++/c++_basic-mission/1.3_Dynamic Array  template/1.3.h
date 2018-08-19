#ifndef _CDARRAY_H_
#define _CDARRAY_H_

#include<iostream>
using namespace std;
#define SAFEDELETES(p)   if(p) {delete [] p; p=NULL;}
#define SAFEJUDGEMENT(p)  if(p==NULL) {cout<<"no ehough memory"<<endl; return 0;}

template <typename DataType>
class CDArray
{	
	public:
	 CDArray();          
	 CDArray(int nSize, DataType dValue);    
	 ~CDArray();      
     CDArray(CDArray const &arr);
	 void  	   Print();             
	int        GetSize();          
	int        SetSize(int nSize);  
	int	DeleteAt(int nIndex);			
	double GetAt (int nIndex);					
	
	int InsertAt(int nIndex, DataType dValue);	
	int SetAt (int nIndex, DataType dValue);     
	int Pushback(DataType dValue);
	CDArray<DataType>& CDArray<DataType>::operator = (const CDArray<DataType>& array);
	
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
	DataType    *m_pData;   
	int        m_nSize; 
	int        m_nMax;	
};

#endif

//----------------------------------------------------------------

template<typename DataType>
CDArray<DataType>::CDArray()
{
	Init();  
}

template <typename DataType>
CDArray<DataType>::CDArray(int nSize, DataType dValue = 0)  
{	
	m_nSize=nSize; 
	DataType *a=new DataType [m_nSize]; 
	m_pData=a;
	for(int i=0;i<m_nSize;i++)
	{
		m_pData[i]=0;
	}
}

template <typename DataType>
CDArray<DataType>::~CDArray()
{
	 Free();	
}

template <typename DataType>
void CDArray<DataType>::Init() 
{
	m_nSize=0;
	m_pData=NULL;
	m_nMax=0;
	cout<<"init"<<endl;
}

template <typename DataType>
void CDArray<DataType>::Free()	
{
	if(m_pData!= NULL)
	{
		delete [] m_pData;
	}
	cout<<"free"<<endl;
}

template <typename DataType>
int CDArray<DataType>::SetSize(int nSize)
{
	int mn;
	mn=nSize;
		if(nSize<m_nSize)
		{	
			DataType *m_newzhizhen = new DataType [mn];
			if(m_newzhizhen==NULL)
			{
				cout<<"no enough memory"<<endl;
				return 0;
			}

			for(int i=0;i<mn;i++)
			{
				m_newzhizhen[i]= m_pData[i];
			}
				SAFEDELETES(m_pData);
				m_pData=m_newzhizhen;
				m_nSize=nSize;
				return 1;
		}	
		if(nSize>m_nSize)
		{
		DataType *m_newzhizhen = new DataType [mn];
			if(m_newzhizhen==NULL)
			{
				cout<<"no enough memory"<<endl;
				return 0;
			}
			for(int i=0;i<m_nSize;i++)
			{
				m_newzhizhen[i]= m_pData[i];
			}
			for(int i=m_nSize;i<mn;i++)
			{
				m_newzhizhen[i]=0;
			}
				SAFEDELETES(m_pData);
				m_pData=m_newzhizhen;
				m_nSize=nSize;
				return 1;
		}
		if(nSize==m_nSize)
		{
			return 1;
		}
}

template <typename DataType>
int CDArray<DataType>::SetAt(int nIndex, DataType dValue)
{	
	m_pData[nIndex]=dValue; 
	 return 1;
}


template <typename DataType>
void  CDArray<DataType>::Print()
{
	for(int i=0;i<m_nSize;i++)
	{
		cout<<m_pData[i]<<endl;
	}
}

template <typename DataType>
int CDArray<DataType>::Pushback(DataType dValue) 
{
	if(m_nSize==m_nMax||m_nMax==0)
	{
			DataType *m_newzhizhen = NULL;
			if(m_nSize==0)
			{m_nMax=1;}
			else
			{m_nMax= m_nSize*2;}		
			m_newzhizhen = new DataType [m_nMax];
			SAFEJUDGEMENT (m_newzhizhen);
				for( int i=0;i<m_nSize;i++ )
			{
				m_newzhizhen[i]=m_pData[i];
		
			}
				m_newzhizhen[m_nSize]=dValue;
				if(m_pData) delete [] m_pData;
				m_pData=m_newzhizhen;
				m_nSize++;
	}
	else 
	{
		m_pData[m_nSize]=dValue;
		m_nSize++;
	}
	return 0;
}

template <typename DataType>
int CDArray<DataType>::DeleteAt(int nIndex)
{
	if(!InvalidateIndex(nIndex))
		{return 0;}
	else
	{
		DataType *m_newzhizhen=NULL;
		m_newzhizhen= new DataType [m_nSize-1];
		SAFEJUDGEMENT(m_newzhizhen);
		if(nIndex==0)
		{
			for(int i=1;i<m_nSize;i++)
			{	
				m_newzhizhen[i-1]=m_pData[i];
			}
		}
		if(nIndex!=0)
		{		for(int i=0;i<nIndex;i++)
			{
				m_newzhizhen[i]=m_pData[i];
			}
			    for(int i=nIndex;i<m_nSize-1;i++)
			{
				m_newzhizhen[i]=m_pData[i+1];
			}
		}
	SAFEDELETES(m_pData);
		m_pData=m_newzhizhen;
		m_nSize--;
		return 0;
	}
}


template <typename DataType>
int  CDArray<DataType>::InsertAt(int nIndex,  DataType dValue)
{		cout<<nIndex<<" "<<dValue<<endl;
	if (!InvalidateIndex(nIndex))
	{
		cout << "Index is invalide in InsertAt()!" << endl;
		return 0;
	}
	else
	{	 DataType *m_newzhizhen = NULL;
		if(m_nSize==0)
		{	
			m_newzhizhen = new  DataType[1];
			m_pData=m_newzhizhen;
			m_pData[0]=dValue;
			m_nSize=1;
		}
		else	
		{	
			m_newzhizhen = new  DataType[m_nSize+1];
			SAFEJUDGEMENT(m_newzhizhen);
			for (int i = 0; i < nIndex; i++)
			{
				m_newzhizhen[i] = m_pData[i];
			}
			m_newzhizhen[nIndex] = dValue;
			for (int i = nIndex+1; i < m_nSize+1; i++)
			{
				m_newzhizhen[i] = m_pData[i-1];
			}
			
			if(m_pData) delete [] m_pData; 
			m_pData = m_newzhizhen;
			
			m_nSize++;
		}	
		return 1;
	}
}

	template <typename DataType>
double  CDArray<DataType>::GetAt(int nIndex)
{
	if( InvalidateIndex(nIndex) )
	{
		cout << "Invalid" << endl;
		return 0;
	}
	else
	{
		return m_pData[nIndex];
	}
}

	template <typename DataType>
CDArray<DataType>::CDArray(const CDArray& arr)
{
	m_pData = new DataType[arr.m_nSize];
	for (int i = 0; i < arr.m_nSize; i++)
	{
		m_pData[i] = arr.m_pData[i];
	}
	m_nSize = arr.m_nSize;
}

template <typename DataType>
CDArray<DataType>& CDArray<DataType>::operator = (const CDArray<DataType>& array)
{
	if (this == &array) return *this;
	m_pData = new DataType[array.m_nSize];
	for (int i = 0; i < array.m_nSize; i++)
	{
		m_pData[i] = array.m_pData[i];
	}
	m_nSize = array.m_nSize;
	return *this;
}
