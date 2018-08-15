
#define SAFEDELETES(p)   if(p) {delete [] p; p=NULL;}
#define SAFEJUDGEMENT(p)  if(p==NULL) {cout<<"no ehough memory"<<endl; return 0;}

template <typename DataType>
class CDArray
{	
	
	public:
	 CDArray();            // 缺省构造函数
	 CDArray(int nSize, DataType dValue);    // 其他构造函数，设置一定数组大小，并设置所有元素为0；当然还可以定义其他不同参数的构造函数，以方便用户使用
	 ~CDArray();        // 析构函数
     CDArray(CDArray const &arr);
	 void  	   Print();             // 输出显示所有数组元素的值
	int        GetSize();           // 获取数组大小（元素个数）
	int        SetSize(int nSize);  
	int	DeleteAt(int nIndex);			// 从数组中删除一个元素
	double GetAt (int nIndex);					// 获取某个元素
	
	int InsertAt(int nIndex, DataType dValue);	// 插入一个新的元素到数组中
	int SetAt (int nIndex, DataType dValue);      // 设置某个元素的值
	int Pushback(DataType dValue);// 追加一个新的元素到数组末尾
	CDArray<DataType>& CDArray<DataType>::operator = (const CDArray<DataType>& array);// 重载赋值操作符号"="
	

private:
	void    Init();        // 初始化
	void    Free();        // 释放动态内存
	inline    int    InvalidateIndex(int nIndex)
	{	if (nIndex<0||nIndex> m_nSize)
		{
			return 0;
		}
			else
		{
			return 1;
		}// 判断下标的合法性
	}
private:
	DataType    *m_pData;    // 存放数组的动态内存指针
	int        m_nSize; // 数组的元素个数
	int        m_nMax;	//预留给动态数组的内存大小
};

template<typename DataType>
CDArray<DataType>::CDArray()
{
	Init();  //缺省构造函数

}

template <typename DataType>
CDArray<DataType>::CDArray(int nSize, DataType dValue = 0)  //其他构造函数，设置一定数组大小，并设置所有元素为0；当然还可以定义其他不同参数的构造函数，以方便用户使用
{	

	m_nSize=nSize; cout<<"设置值"<<endl;
	DataType *a=new DataType [m_nSize]; cout<<"分配内存"<<endl;
	m_pData=a;
	
	for(int i=0;i<m_nSize;i++)
	{
		m_pData[i]=0;
	}


}

template <typename DataType>
CDArray<DataType>::~CDArray()
{
	 Free();	//析构函数

}


template <typename DataType>
void CDArray<DataType>::Init()  //初始化
{
	m_nSize=0;
	m_pData=NULL;
	m_nMax=0;
	cout<<"init"<<endl;

}

template <typename DataType>
void CDArray<DataType>::Free()	//释放内存
{
	if(m_pData!= NULL)
	{
		delete [] m_pData;
	}
	cout<<"free"<<endl;

}




template <typename DataType>
int CDArray<DataType>::SetSize(int nSize) // 重新设置数组的大小。注：若nSize小于原数组大小，可截断取前nSize个元素作为新数组的元素；若nSize大于原数组大小，新增的元素的值设置缺省值0即可
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
	if(m_pData==NULL)
		//{cout<<"退出1"<<p<<endl;return 0;}
	
	if(nIndex<0||nIndex>=m_nSize)
		//{cout<<"退出2"<<endl;return 0;}
	
	m_pData[nIndex]=dValue; 
	    //cout<<"分配值完毕"<<endl;
	return 1;
}


template <typename DataType>
void  CDArray<DataType>::Print()
{
	cout<<"打印值"<<endl;

	for(int i=0;i<m_nSize;i++)
	{
		cout<<m_pData[i]<<endl;
		
	}
	
}

template <typename DataType>
int CDArray<DataType>::Pushback(DataType dValue)  //追加一个新的元素到数组末尾
{
	if(m_nSize==m_nMax||m_nMax==0)
	{

			
			DataType *m_newzhizhen = NULL;
	
			if(m_nSize==0)
			{m_nMax=1;}
			else
			{m_nMax= m_nSize*2;}		//分配两倍的内存
	
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
	else //(m_nSize<m_nMax)
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
		cout << "无效的下标" << endl;
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
