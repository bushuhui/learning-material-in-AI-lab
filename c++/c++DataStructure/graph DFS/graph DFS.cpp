#include<iostream>

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode
{
	int data;
	ArcNode *firstarc;
}VNode;

int visited[5] = {0,0,0,0,0};

void CreatGraph(int n , VNode G[])
{
	int i , e;  
	ArcNode *p , *q ;
	std::cout<<"Input the information of the vertex "<<std::endl;
	for(i=0;i<n;i++)
	{	
		std::cin>>G[i].data ;
		G[i].firstarc = NULL;
	}
	for(i=0;i<n;i++)
	{
		std::cout<<"Creat the edges for the "<<i<<"th vertex"<<std::endl;
		std::cin>>e;
		while(e != -1)
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->next = NULL;
			p->adjvex = e;
			if(G[i].firstarc == NULL)
				G[i].firstarc = p;
				else
				q->next = p;
			q = p;
			std::cin>>e;
		}
	}
}

int FirstAdj(VNode G[] , int v)
{	
	std::cout<<"FirstAdj"<<std::endl;
	if(G[v].firstarc != NULL) 
		return (G[v].firstarc)->adjvex;
	return -1;
}

int NextAdj(VNode G[] , int v)
{
	std::cout<<"Nextadj"<<std::endl;
	ArcNode *p; 
	p = G[v].firstarc;
	while( p != NULL)
	{
		if(visited[p->adjvex])
			p = p->next;
		else
			return p->adjvex;
	}
	return -1;
}

void DFS(VNode G[] , int v)            //Depth First Search
{
	int w;
	std::cout<<G[v].data<<" -DFS"<<std::endl;
	visited[v] = 1;
	w = FirstAdj(G , v);
	while(w != -1)
	{
		if(visited[w] == 0)
			DFS(G , w);
		w= NextAdj(G,v);
	}
}

int main()
{
	VNode G[5];
	CreatGraph(5,G);
	DFS(G,0);

	return 0;
}











