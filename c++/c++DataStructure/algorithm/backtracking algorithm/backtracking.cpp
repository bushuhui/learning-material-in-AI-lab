#include<iostream>
using namespace std;

int count = 0;
int IsCorrect(int i , int j , int (*Q)[4])
{
	int s , t;                   //Judge the row
	for(s=i , t=0;t<4;t++)
		if(Q[s][t] == 1 && t != j)
			return 0;
	for(t=j , s=0;s<4;s++)		//Judge the column
		if(Q[s][t] == 1 && s!=i)
			return 0;
	for(s=i-1 , t=j-1;s>=0 && t>=0;s-- , t--) //Judgr the Top Left
		if(Q[s][t] == 1)
			return 0;
	for(s=i+1 , t=j+1;s<4 && t<4;s++ , t++)		//Judge the Botom Right
		if(Q[s][t] == 1)
			return 0;
	for(s=i-1 , t=j+1;s>=0 && t<4;s-- , t++)	//Judge the Top Right
		if(Q[s][t] == 1)
			return 0;
	for(s=i+1 , t=j-1;s<4 && t>=0;s++ , t--)	//Judge the Bottom Left
		if(Q[s][t] == 1)
			return 0;

	return 1;
}

void Queen(int j , int (*Q)[4])
{
	int i , k;
	if(j == 4)
	{
		for(i=0;i<4;i++)
		{
			for(k=0;k<4;k++)
				cout<<Q[i][k];
			cout<<endl;
		}
		cout<<endl;
		count++;
		return;
	}
	for(i=0;i<4;i++)
	{
		if(IsCorrect(i , j , Q))
		{
			Q[i][j] = 1;
			Queen(j+1 , Q);
			Q[i][j] = 0;
		}
	}
}

int main()
{
	int Q[4][4];
	int i , j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			Q[i][j] = 0;
	Queen(0 , Q);
	cout<<"The number of the answers of four queens are"
	<<count<<endl;

	return 0;
}


