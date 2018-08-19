#ifndef _SQLIST_H
#define _SQLIST_H

#include<iostream>
#define MaxSize 10

class Sqlist
{

public:
	Sqlist();
	~Sqlist();
	void InitList(int length);
	void ShowSurplusSpace();
	void Insert(int i ,int x);
	void Delete(int i);
	void Print();

private:
	int len;
	int list[MaxSize];
};

#endif