#include<iostream>
#include<math.h>

#define STACK_INIT__SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

void InitStack(SqStack *s)
{
	s->base = (ElemType*)malloc(STACK_INIT__SIZE * sizeof(ElemType));
	if(!s->base)
		exit(0);
	s->top = s->base;
	s->stacksize = STACK_INIT__SIZE;

}

void Push(SqStack *s , ElemType e)
{
	if(s->top - s->base >= s->stacksize)
	{
		s->base = (ElemType*)realloc(s->base , (s->stacksize + 
			STACKINCREMENT) * sizeof(ElemType));
		if(!s->base)
			exit(0);
		s->top = s->base + s->stacksize;
		s->stacksize = s->stacksize + STACKINCREMENT;
	}
	*(s->top) = e;
	s->top++;
}

void Pop(SqStack *s , ElemType *e)
{
	if(s->top == s->base)
		return;
	*e = *--(s->top);
}

int StackLen(SqStack s)
{
	return (s.top - s.base);
}

int main()
{
	ElemType c;
	SqStack s;
	int len , i , sum = 0;
	std::cout<<"Please input a Binary digit"<<std::endl;
	InitStack(&s);
	std::cin>>c;
	while(c != '#')
	{
		Push(&s , c);
		std::cin>>c;
	}
	getchar();
	len = StackLen(s);

	for(i=0;i<len;i++)
	{
		Pop(&s , &c);		
		sum = sum +(c-48)*pow((float)2,i);
	}
	std::cout<<"Decimal is "<<sum<<std::endl;
	

}

