/*编写一个程序，要求：从终端输入一组整数（大于十个数），以0作为结束标志，
将这一整组数存放在一个链表中（结束标志0不包括在内），打印出该链表的值。
然后删除该链表中的第五个元素，打印出删除后的结果。最后在内存中释放掉该链表*/

#include<iostream>

typedef int ElemType;
typedef struct node 
{
	ElemType data;
	struct node *next;
}LNode , *LinkList;

LinkList GreatLinkList(int n)
{
	LinkList p , r , list = NULL;
	ElemType e;
	for(int i=0;i<n;i++)
	{
		std::cin>>e;
		p = (LinkList)malloc(sizeof(LNode));
		p->data = e;
		p->next = NULL;
		if(!list)
			list = p;
		else
			r->next = p;
		r=p;
	}
	return list;
}

void InsertLinkList(LinkList list , LinkList q , ElemType e)
{
	LinkList r;
	r=(LinkList)malloc(sizeof(LNode));
	r->data = e;
	if(!list)
	{
		list = r;
		r->next = NULL;
	}
	else
	{
		r->next = q->next;
		q->next = r;
	}
}

void Delete(LinkList list , LinkList q)
{
	LinkList r;
	if(q==list)    //taking the first node situation into account
	{
		list = q->next;
		free(q);
	}
	else
	{
		for(r = list;r->next!=q;r = r->next);  //Find the the elenment ahead of q and give the site to r
			if(r->next != NULL)
			{
				r->next = q->next;			//Give the site which behind q to r for connecting them 
				free(q);
			}
	}
}

void DestroyLinkList(LinkList list)
{
	LinkList p , q;
	p = list;
	while(p)    //use two pointers for easily exchanging the values 
	{
		q = p->next;
		free(p);
		p=q;
	}
	list = NULL;
}


int main()
{	
	int e , i;
	LinkList a,b;
	a=b=GreatLinkList(1);
	std::cin>>e;
	while(e)
	{
		InsertLinkList(a,b,e);
		b = b->next;
		std::cin>>e;
	}
	b=a;
	std::cout<<"The content of the LinkList"<<std::endl;
	while(b)
	{
		std::cout<<b->data<<" ";
		b = b->next;
	}
	std::cout<<std::endl;
	b=a;	
	std::cout<<"delete the fifth element"<<std::endl;
	for(i=0;i<4;i++)
	{
		b=b->next;
	}
	Delete(a,b);
	b=a;
	while(b)
	{
		std::cout<<b->data<<" ";
		b=b->next;
	}
	std::cout<<std::endl;
	DestroyLinkList(a);

	return 0;
}

/*
*/



