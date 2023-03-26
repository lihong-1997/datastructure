#define _CRT_SECURE_NO_WARNINGS 1
#include "avltree.h"
#include <stdio.h>


int main()
{
	AvlTree T;
	T = MakeEmpty(NULL);

	int arr[8] = { 5,3,6,8,1,2,7,4 };

	for (int i = 0; i < 8; ++i)
	{
		T = Insert(arr[i], T);
	}
	PreOrderTraversal(T);

	return 0;
}