#ifndef __CDARRAY_H__   //  Add the marco to avoid multi-include
#define __CDARRAY_H__

#define SAFEDELETES(p)   if(p) {delete [] p; p=NULL;}
#define SAFEJUDGEMENT(p)  if(p==NULL) {cout<<"no ehough memory"<<endl; return 0;}
#include<iostream>
using namespace std; 

class CDArray
{	

public:
    CDArray();                              // Default constructor 
    CDArray(int nSize, double dValue);      // Other constructor: set all elements to 0 value
    ~CDArray();                             // Destructor
    CDArray(CDArray const &arr);

    void  	   Print();                     // Show all elements of values in the array
    int        GetSize();                   // Get the size of array
    int        SetSize(int nSize);
    int	DeleteAt(int nIndex);               // Delete a element from the array 
    double GetAt (int nIndex);					// Get a element

    int InsertAt(int nIndex, double dValue);	// Insert a new element into array
    int SetAt (int nIndex, double dValue);      // Set a element value
    int Pushback(double dValue);				//Pushback a element to array 
    CDArray& CDArray::operator = (const CDArray& array);// Overloaded assignment operator "="


private:
    void    Init();        // Initialization
    void    Free();        // Free dynamic memory

    inline int InvalidateIndex(int nIndex)
    {	if (nIndex<0||nIndex> m_nSize)
        {
            return 0;
        }
        else
        {
            return 1;
        }// Judge the legality of subscripts
    }

private:
    double    *m_pData;    // Array of pointers which is allocated dynamic memory
    int        m_nSize;	  //  The number of elements in array
};

#endif 