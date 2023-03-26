#include "avltree.h"

#include <stdio.h>
#include <stdlib.h>

struct AvlNode
{
	ElementType element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

static int Max(int LH, int RH)
{
	return (LH > RH) ? LH : RH;
}

static int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}

static Position SingleRotateWithLeft(Position k2) //LL
{
	Position k1;
	k1 = k2->Left;

	k2->Left = k1->Right;
	k1->Right = k2;

	k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
	k1->Height = Max(Height(k1->Left), k2->Height) + 1;

	return k1;
}

static Position SingleRotateWithRight(Position k2) //RR
{
	Position k1;
	k1 = k2->Right;

	k2->Right = k1->Left;
	k1->Left = k2;

	k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
	k1->Height = Max(k2->Height, Height(k1->Right)) + 1;

	return k1;
}

static Position DoubleRotateWithLeft(Position k3) //LR
{
	k3->Left = SingleRotateWithRight(k3->Left);

	return SingleRotateWithLeft(k3);
}

static Position DoubleRotateWithRight(Position k3) //RL
{
	k3->Right = SingleRotateWithLeft(k3->Right);

	return SingleRotateWithRight(k3);
}

AvlTree MakeEmpty(AvlTree T)
{
	if (T)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}

	return NULL;
}

Position Find(ElementType X, AvlTree T)
{
	if (T == NULL)
		return NULL;
	if (X < T->element) 
		return Find(X, T->Left);
	else if (X > T->element) 
		return Find(X, T->Right);
	else
		return T;
}
Position FindMin(AvlTree T)
{
	if (T == NULL)
		return NULL;

	if (T->Left != NULL)
		return FindMin(T->Left);
	else
		return T;
}
Position FindMax(AvlTree T)
{
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;

	return T;
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct AvlNode));
		if (T == NULL)
		{
			fprintf(stderr, "out of space");
			exit(1);
		}
		else
		{
			T->element = X;
			T->Left = T->Right = NULL;
			T->Height = 0;
		}
	}
	else if (X < T->element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			//进行旋转
			if (X < T->Left->element) //通过值判断麻烦节点在发现者左子树的左子树中或是右子树中
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if (X > T->element)
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			//进行旋转
			if (X > T->Right->element) //通过值判断麻烦节点在发现者右子树的左子树中或是右子树中
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}

	//更新树高度
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

	return T;
}

ElementType Retrieve(Position P)
{
	return P->element;
}

void PreOrderTraversal(AvlTree T)
{
	if (T)
	{
		printf("%d,height %d\n", T->element, T->Height);
		PreOrderTraversal(T->Left);
		PreOrderTraversal(T->Right);
	}
}