/*
 *�����λʱǰһ��ָ��ļ�¼����ķ�����:
 *1.��д FindPrevious ������ʱ�临�ӶȽϴ�
 *2.�ĳ������С�����¼����ֱ�ӣ�����������ĿҪ��֮����Ҫ�Ӵ�С��ӡ�����ܴ��ڵݹ�ջ����ķ��գ�
 *3.��������ĳ�˫����(����)��
 */

#ifndef BIGINT_H
#define BIGINT
#include <stdio.h>
#include <stdlib.h>

struct Node;

typedef struct Node* PtrToNode;
struct Node
{
	int Coefficient;
	int Exponent;
	PtrToNode Previous;
	PtrToNode Next;
};
typedef PtrToNode BigInt;
typedef PtrToNode Position;

int IsLast(Position P, BigInt BI);
void Insert(int c, int e, BigInt BI, Position P);
void PrintBigInt(BigInt BI);
void BigIntConstructor(int* C, int* E, int N, BigInt BI);
BigInt BigIntAdd(BigInt BI1, BigInt BI2);
BigInt BigIntMulti(BigInt BI1, BigInt BI2);
void FormatBigInt(BigInt BI);
void CountDigits(BigInt BI, int* counts); //����0-9����Ƶ��
void DeleteBigInt(BigInt BI);
unsigned Length(BigInt BI);


#endif
