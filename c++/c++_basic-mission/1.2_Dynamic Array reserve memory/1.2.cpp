#include"CDArray.h"

CDArray::CDArray()
{
	Init();  
}

CDArray::CDArray(int nSize, double dValue = 0)  
{	
	m_nSize=nSize; 
	double *a=new double [m_nSize]; 
	m_pData=a;
	for(int i=0;i<m_nSize;i++)
	{
		m_pData[i]=0;
	}
}

CDArray::~CDArray()
{
	 Free();	
}

void CDArray::Init()  
{
	m_nSize=0;
	m_pData=NULL;
	m_nMax=0;
}

void CDArray::Free()	
{
	if(m_pData!= NULL)
	{
		delete [] m_pData;
	}
}

int CDArray::SetSize(int nSize)
{
	int mn;
	mn=nSize;
			if(nSize<m_nSize)
		{	
			double *m_newzhizhen = new double [mn];
			if(m_newzhizhen==NULL)
			{
				std::cout<<"no enough memory"<<std::endl;
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
		double *m_newzhizhen = new double [mn];
			if(m_newzhizhen==NULL)
			{
				std::cout<<"no enough memory"<<std::endl;
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

int CDArray::SetAt(int nIndex, double dValue)
{	
	if(m_pData==NULL)
	if(nIndex<0||nIndex>=m_nSize)
	m_pData[nIndex]=dValue; 
	return 1;
}


void  CDArray::Print()
{
	for(int i=0;i<m_nSize;i++)
	{
		cout<<m_pData[i]<<endl;
	}
}

int CDArray::Pushback(double dValue)  //追加一个新的元素到数组末尾
{
	if(m_nSize==m_nMax||m_nMax==0)
	{
			double *m_newzhizhen = NULL;
			if(m_nSize==0){m_nMax=1;}
			else
			{m_nMax= m_nSize*2;}		//分配两倍的内存
			m_newzhizhen = new double [m_nMax];
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
	else //(m_nSize<m_nMax)
	{
		m_pData[m_nSize]=dValue;
		m_nSize++;
	}
	return 0;
}

int CDArray::DeleteAt(int nIndex)
{
	if(!InvalidateIndex(nIndex))
		{return 0;}
	else
	{
		double *m_newzhizhen=NULL;
		m_newzhizhen= new double [m_nSize-1];
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


int  CDArray::InsertAt(int nIndex, double dValue)
{	
	if (!InvalidateIndex(nIndex))
	{
		cout << "Index is invalide in InsertAt()!" << endl;
		return 0;
	}
	else
	{	double *m_newzhizhen = NULL;
		if(m_nSize==0)
		{	
			m_newzhizhen = new double[1];
			m_pData=m_newzhizhen;
			m_pData[0]=dValue;
			m_nSize=1;
		}
		else	
		{	
			m_newzhizhen = new double[m_nSize+1];
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

	
double  CDArray::GetAt(int nIndex)
{
	if( InvalidateIndex(nIndex) )
	{
		std::cout << "Invalid" <<std::endl;
		return 0;
	}
	else
	{
		return m_pData[nIndex];
	}
}

CDArray::CDArray(const CDArray& arr)
{
	m_pData = new double[arr.m_nSize];
	for (int i = 0; i < arr.m_nSize; i++)
	{
		m_pData[i] = arr.m_pData[i];
	}
	m_nSize = arr.m_nSize;
}

CDArray& CDArray::operator = (const CDArray& array)
{
	if (this == &array) return *this;
	m_pData = new double[array.m_nSize];
	for (int i = 0; i < array.m_nSize; i++)
	{
		m_pData[i] = array.m_pData[i];
	}
	m_nSize = array.m_nSize;
	return *this;
}
