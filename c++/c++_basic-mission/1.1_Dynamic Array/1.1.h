#ifndef __CDARRAY_H__   // FIXME: add the marco to avoid multi-include
#define __CDARRAY_H__

#define SAFEDELETES(p)   if(p) {delete [] p; p=NULL;}
#define SAFEJUDGEMENT(p)  if(p==NULL) {cout<<"no ehough memory"<<endl; return 0;}

class CDArray
{	

public:
    CDArray();                              // 缺省构造函数 FIXME: change the comment to English
    CDArray(int nSize, double dValue);      // 其他构造函数，设置一定数组大小，并设置所有元素为0；当然还可以定义其他不同参数的构造函数，以方便用户使用
    ~CDArray();                             // 析构函数
    CDArray(CDArray const &arr);

    void  	   Print();                     // 输出显示所有数组元素的值
    int        GetSize();                   // 获取数组大小（元素个数）
    int        SetSize(int nSize);
    int	DeleteAt(int nIndex);               // 从数组中删除一个元素
    double GetAt (int nIndex);					// 获取某个元素

    int InsertAt(int nIndex, double dValue);	// 插入一个新的元素到数组中
    int SetAt (int nIndex, double dValue);      // 设置某个元素的值
    int Pushback(double dValue);// 追加一个新的元素到数组末尾
    CDArray& CDArray::operator = (const CDArray& array);// 重载赋值操作符号"="


private:
    void    Init();        // 初始化
    void    Free();        // 释放动态内存

    inline int InvalidateIndex(int nIndex)
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
    double    *m_pData;    // 存放数组的动态内存指针
    int        m_nSize; // 数组的元素个数
};
