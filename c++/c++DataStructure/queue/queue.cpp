#include<iostream>

typedef char ElemType;
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}QNode , *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;

}LinkQueue;

void InitQueue(LinkQueue *q)
{
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!q->front)
		exit(0);
	q->front->next = NULL;
}

void EnQueue(LinkQueue *q , ElemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!q->front)
		exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

void DeQueue(LinkQueue *q , ElemType *e)
{
	QueuePtr p;
	if(q->front == q->rear)
		return;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if(q->rear == p)
		q->rear = q->front;
	free(p);
}

int main()
{
	ElemType e;
	LinkQueue q;
	InitQueue(&q);
	std::cout<<"Please input a string into a queue "<<std::endl;
	std::cin>>e;
	while(e != '@')
	{
		EnQueue(&q,e);
		std::cin>>e;
	}
	std::cout<<"The string into the queue is"<<std::endl;
	while(q.front != q.rear)
	{
		DeQueue(&q,&e);
		std::cout<<e;
	}
	std::cout<<std::endl;

}



