#include "linkedlist.h"
#include <iostream>

using namespace linkedlist;
template class List<int>; //

int main77()
{
	int N = 5; //����
	int M = 0; //����

	List<int> josephus;
	for (int i = 1; i <= N; ++i)
	{
		josephus.Insert(i);
	}

	Node<int>* man = josephus.First();
	size_t num = josephus.size();

	while (num != 1)
	{
		for (int j = 0;j < M;j++)
			man = josephus.IsLast(man) ? josephus.First() : josephus.Advance(man);

		int man_num = josephus.Retrieve(man);
		man = josephus.IsLast(man) ? josephus.First() : josephus.Advance(man); //���������һ��������������
		/*
		 * ����˫��������Խ�ʡRemoveʱ��
		 */
		josephus.Remove(man_num);

		num = josephus.size();
	}

	josephus.Traverse(); //��ʤ����

	return 0;
}