#include<iostream>
using namespace std;

void Sort(int w[] , int t[] , int n)
{
	int i , j ,tmp;
	int *w_tmp = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		t[i] = i;
	for (i = 0; i < n; i++)
		w_tmp[i] = w[i];
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n-i-1; j++)
			if(w_tmp[j]>w_tmp[j+1])
			{
				tmp = w_tmp[j];
				w_tmp[j] = w_tmp[j+1];
				w_tmp[j+1] = tmp;
				tmp = t[j];
				t[j] = t[j+1];
				t[j+1] = tmp;
			}
}

void Loading(int x[] , int w[] , int c , int n)
{
	int i , s=0;
	int *t = (int*)malloc(sizeof(int)*n);
	Sort(w , t , n);
	for (i = 0; i < n; i++)
		x[i] = 0;
	for (i = 0; i < n && w[t[i]]<=c; i++)
	{
		x[t[i]] = 1;
		c = c - w[t[i]];
	}
}

int main()
{
	int x[5] , w[5] , c , i;
	cout<<"Please input the maximum loading of the sheep "<<endl;
	cin>>c;
	cout<<"Please input the weight of Five box "<<endl;
	for(i=0;i<5;i++)
		cin>>w[i];
	Loading(x , w , c , 5);
	for(i=0;i<5;i++)
	{
		if(x[i] == 1)
			cout<<"box: "<<i<<" ";
	}
	cout<<endl;
}

