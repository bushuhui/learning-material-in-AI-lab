#ifndef __CDARRAY_H__   // FIXME: add the marco to avoid multi-include
#define __CDARRAY_H__

#define SAFEDELETES(p)   if(p) {delete [] p; p=NULL;}
#define SAFEJUDGEMENT(p)  if(p==NULL) {cout<<"no ehough memory"<<endl; return 0;}

class CDArray
{	

public:
    CDArray();                              // ȱʡ���캯�� FIXME: change the comment to English
    CDArray(int nSize, double dValue);      // �������캯��������һ�������С������������Ԫ��Ϊ0����Ȼ�����Զ���������ͬ�����Ĺ��캯�����Է����û�ʹ��
    ~CDArray();                             // ��������
    CDArray(CDArray const &arr);

    void  	   Print();                     // �����ʾ��������Ԫ�ص�ֵ
    int        GetSize();                   // ��ȡ�����С��Ԫ�ظ�����
    int        SetSize(int nSize);
    int	DeleteAt(int nIndex);               // ��������ɾ��һ��Ԫ��
    double GetAt (int nIndex);					// ��ȡĳ��Ԫ��

    int InsertAt(int nIndex, double dValue);	// ����һ���µ�Ԫ�ص�������
    int SetAt (int nIndex, double dValue);      // ����ĳ��Ԫ�ص�ֵ
    int Pushback(double dValue);// ׷��һ���µ�Ԫ�ص�����ĩβ
    CDArray& CDArray::operator = (const CDArray& array);// ���ظ�ֵ��������"="


private:
    void    Init();        // ��ʼ��
    void    Free();        // �ͷŶ�̬�ڴ�

    inline int InvalidateIndex(int nIndex)
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
    double    *m_pData;    // �������Ķ�̬�ڴ�ָ��
    int        m_nSize; // �����Ԫ�ظ���
};
