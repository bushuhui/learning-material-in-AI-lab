/*
��дһ������ʵ��{2,5,6,3,7,8,0,9,12,1} ��ð������
Ҫ��Ӵ�С���У����������������Ԫ��
*/

#include<iostream>
using namespace std;
void BubbleSort(int k[] , int n)
{
	int i , j , tmp ,flag = 1;
	for(i=1;i<=n-1 && flag == 1 ;i++)
	{
		flag = 0;
		for(j=1;j<=n-1;j++)
		{
			if(k[j]<k[j+1])
			{
				tmp = k[j+1];
				k[j+1] = k[j];
				k[j] = tmp;
				flag = 1;
			}
		}
	}
}

int main()
{
    // FIXME: 
    //   (1) how to sort arbitary size array
	//   (2) how to load data from file to evalute/test the programm

    int i , a[11] = {-111,2,5,6,3,7,8,0,9,12,1};
	cout<<"The original data array is"<<endl;
	for(i=1;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;

    BubbleSort(a,10);
	cout<<"The result of the array is"<<endl;
	for(i=1;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}
