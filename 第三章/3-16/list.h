#ifndef _LIST_H
#define _LIST_H

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;     // list header
typedef PtrToNode Position; // list element

List MakeEmpty();                         //������ͷ
List LinkedListCreate();                  //��terminal��������
List LinkedListCreateFromArray(int* array, int len); //�����鴴������
void DeleteList(List L);                  //ɾ������
int IsEmpty(List L);                      //�ж������Ƿ�Ϊ��
int IsLast(Position p, List L);           //�жϽڵ��Ƿ�Ϊ����ĩβ�ڵ�

void Insert(int X, List L, Position p);//
void Delete(int X, List L);
void Delete_pPre(int X, List L, Position p);
Position Find(int X, List L);
Position FindKth(int K, List L);
Position FindPrevious(int X, List L);

int Length(List L);
int getIndex(Position p, List L);
int Retrieve(Position p);

void PrintList(List L); //��ӡ����
void PrintList_recursion(List L); //�ݹ��ӡ����
//Position Header(List L);
Position First(List L);
Position Advance(Position p); //ǰ��һ���ڵ�

void LinkedListSwap(Position previousNode); //�������ڵ�

#endif /* _LIST_H */
