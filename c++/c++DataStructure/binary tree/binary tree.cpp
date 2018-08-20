/*����һ����������������ַ�D�Ĳ���
�ο����룺-----��ABC @@ D @@ E @ F @@��  @����ո�
������3��*/
 


#include<iostream>

typedef char Elemtype;
typedef struct BiTNode
{
	Elemtype data;
	struct BiTNode *lchild , *rchild;

}BiTNode , *BiTree;  //BiTNode *t  is equivlent to BiTree t

void CreatBiTree(BiTree *T)  //Nested function where lchild and rchild are placed 
{
	char c;
	std::cin.get(c);  // One letter at a time
	if(c = ' ')
		*T = NULL;
	else
	{
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreatBiTree(&(*T)->lchild);  //It will creat left child all the time unless get a space
		CreatBiTree(&(*T)->rchild);  
	}
}// The number of the spaces is important which determines the level of the next letter

void Visit(char c , int level)
{
	if(c ==	'D')
		std::cout<<c<<" is at "<<level<<" of BiTree "<<std::endl;

}

void PreOrderTraverse(BiTree T , int level)
{
	if(T)
	{	Visit(T->data , level);
		PreOrderTraverse(T->lchild , level+1);
		PreOrderTraverse(T->rchild , level+1);
	}
} //Two nested functions in one is a easy way for traversing whole tree
  //Setting a proper condition such as "T == NULL" is important for stopping the process

int main()
{
	int level = 1;
	BiTree T = NULL;
	CreatBiTree(&T);
	PreOrderTraverse(T , level);

	return 0;
}


