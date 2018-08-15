
#define SAFEDELETES(p)   if(p) {delete [] p; p=NULL;}
#define SAFEJUDGEMENT(p)  if(p==NULL) {cout<<"no ehough memory"<<endl; return 0;}

template <typename DataType>
class CDArray
{	
	
	public:
	 CDArray();            // ȱʡ���캯��
	 CDArray(int nSize, DataType dValue);    // �������캯��������һ�������С������������Ԫ��Ϊ0����Ȼ�����Զ���������ͬ�����Ĺ��캯�����Է����û�ʹ��
	 ~CDArray();        // ��������
     CDArray(CDArray const &arr);
	 void  	   Print();             // �����ʾ��������Ԫ�ص�ֵ
	int        GetSize();           // ��ȡ�����С��Ԫ�ظ�����
	int        SetSize(int nSize);  
	int	DeleteAt(int nIndex);			// ��������ɾ��һ��Ԫ��
	double GetAt (int nIndex);					// ��ȡĳ��Ԫ��
	
	int InsertAt(int nIndex, DataType dValue);	// ����һ���µ�Ԫ�ص�������
	int SetAt (int nIndex, DataType dValue);      // ����ĳ��Ԫ�ص�ֵ
	int Pushback(DataType dValue);// ׷��һ���µ�Ԫ�ص�����ĩβ
	CDArray<DataType>& CDArray<DataType>::operator = (const CDArray<DataType>& array);// ���ظ�ֵ��������"="
	

private:
	void    Init();        // ��ʼ��
	void    Free();        // �ͷŶ�̬�ڴ�
	inline    int    InvalidateIndex(int nIndex)
	{	if (nIndex<0||nIndex> m_nSize)
		{
			return 0;
		}
			else
		{
			return 1;
		}// �ж��±�ĺϷ���
	}
private:
	DataType    *m_pData;    // �������Ķ�̬�ڴ�ָ��
	int        m_nSize; // �����Ԫ�ظ���
	int        m_nMax;	//Ԥ������̬������ڴ��С
};

template<typename DataType>
CDArray<DataType>::CDArray()
{
	Init();  //ȱʡ���캯��

}

template <typename DataType>
CDArray<DataType>::CDArray(int nSize, DataType dValue = 0)  //�������캯��������һ�������С������������Ԫ��Ϊ0����Ȼ�����Զ���������ͬ�����Ĺ��캯�����Է����û�ʹ��
{	

	m_nSize=nSize; cout<<"����ֵ"<<endl;
	DataType *a=new DataType [m_nSize]; cout<<"�����ڴ�"<<endl;
	m_pData=a;
	
	for(int i=0;i<m_nSize;i++)
	{
		m_pData[i]=0;
	}


}

template <typename DataType>
CDArray<DataType>::~CDArray()
{
	 Free();	//��������

}


template <typename DataType>
void CDArray<DataType>::Init()  //��ʼ��
{
	m_nSize=0;
	m_pData=NULL;
	m_nMax=0;
	cout<<"init"<<endl;

}

template <typename DataType>
void CDArray<DataType>::Free()	//�ͷ��ڴ�
{
	if(m_pData!= NULL)
	{
		delete [] m_pData;
	}
	cout<<"free"<<endl;

}




template <typename DataType>
int CDArray<DataType>::SetSize(int nSize) // ������������Ĵ�С��ע����nSizeС��ԭ�����С���ɽض�ȡǰnSize��Ԫ����Ϊ�������Ԫ�أ���nSize����ԭ�����С��������Ԫ�ص�ֵ����ȱʡֵ0����
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
		//{cout<<"�˳�1"<<p<<endl;return 0;}
	
	if(nIndex<0||nIndex>=m_nSize)
		//{cout<<"�˳�2"<<endl;return 0;}
	
	m_pData[nIndex]=dValue; 
	    //cout<<"����ֵ���"<<endl;
	return 1;
}


template <typename DataType>
void  CDArray<DataType>::Print()
{
	cout<<"��ӡֵ"<<endl;

	for(int i=0;i<m_nSize;i++)
	{
		cout<<m_pData[i]<<endl;
		
	}
	
}

template <typename DataType>
int CDArray<DataType>::Pushback(DataType dValue)  //׷��һ���µ�Ԫ�ص�����ĩβ
{
	if(m_nSize==m_nMax||m_nMax==0)
	{

			
			DataType *m_newzhizhen = NULL;
	
			if(m_nSize==0)
			{m_nMax=1;}
			else
			{m_nMax= m_nSize*2;}		//�����������ڴ�
	
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
		cout << "��Ч���±�" << endl;
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
