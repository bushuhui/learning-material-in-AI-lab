#include<iostream>
using namespace std;
#include"1.2头文件.h"

CDArray::CDArray()
{
	Init();  //缺省构造函数

}

CDArray::CDArray(int nSize, double dValue = 0)  //其他构造函数，设置一定数组大小，并设置所有元素为0；当然还可以定义其他不同参数的构造函数，以方便用户使用
{	

	m_nSize=nSize; cout<<"设置值"<<endl;
	double *a=new double [m_nSize]; cout<<"分配内存"<<endl;
	m_pData=a;
	
	for(int i=0;i<m_nSize;i++)
	{
		m_pData[i]=0;
	}


}

CDArray::~CDArray()
{
	 Free();	//析构函数

}



void CDArray::Init()  //初始化
{
	m_nSize=0;
	m_pData=NULL;
	m_nMax=0;
	cout<<"init"<<endl;

}

void CDArray::Free()	//释放内存
{
	if(m_pData!= NULL)
	{
		delete [] m_pData;
	}
	cout<<"free"<<endl;

}





int CDArray::SetSize(int nSize) // 重新设置数组的大小。注：若nSize小于原数组大小，可截断取前nSize个元素作为新数组的元素；若nSize大于原数组大小，新增的元素的值设置缺省值0即可
{

	int mn;
		mn=nSize;
	
		if(nSize<m_nSize)
		{	
			

			double *m_newzhizhen = new double [mn];

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
		double *m_newzhizhen = new double [mn];

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

int CDArray::SetAt(int nIndex, double dValue)
{	
	if(m_pData==NULL)
		//{cout<<"退出1"<<p<<endl;return 0;}
	
	if(nIndex<0||nIndex>=m_nSize)
		//{cout<<"退出2"<<endl;return 0;}
	
	m_pData[nIndex]=dValue; 
	    //cout<<"分配值完毕"<<endl;
	return 1;
}


void  CDArray::Print()
{
	cout<<"打印值"<<endl;

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
{		cout<<nIndex<<" "<<dValue<<endl;
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
		cout << "无效的下标" << endl;
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
