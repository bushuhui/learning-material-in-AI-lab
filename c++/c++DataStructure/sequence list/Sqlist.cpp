#include"sqlist.h"

Sqlist::Sqlist()
{
	len=0;
}

Sqlist::~Sqlist()
{
	
}

void Sqlist::InitList(int length)
{	
	
	int x;
	for(int n=0 ; n<length; n++)
	{
		std::cin>>x;
		list[n]=x;
	}
	len=6 ;
}


void Sqlist::Insert(int i ,int x)
{
	if(len==MaxSize || i<1 ||i>len+1)
	{
		std::cout<<"inserting is illegal"<<std::endl;
		return;
	}
	for(int t=len-1 ;t>=i-1 ; t--)
	{
		list[t+1]=list[t];
		
	}
	list[i-1]=x;
	len = len + 1;
}

void Sqlist::Delete(int i)
{
	for(int n=i-1;n<=len-1;n++)
	{
		list[n] = list[n+1];
	}
	len = len-1;
}

void Sqlist::ShowSurplusSpace()
{	
	int t;
	t = MaxSize - len; 
	std::cout<<t<<std::endl;
}

void Sqlist::Print()
{
	for(int i=0; i<len;i++)
	{
	std::cout<<list[i]<<" ";
	}
	std::cout<<std::endl;
	ShowSurplusSpace();
}