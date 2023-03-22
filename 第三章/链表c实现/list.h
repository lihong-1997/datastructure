#ifndef _LIST_H
#define _LIST_H

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;     // list header
typedef PtrToNode Position; // list element

List MakeEmpty();                         //创建表头
List LinkedListCreate();
List LinkedListCreateFromArray(int* array, int len);
void DeleteList(List L);                  //删除链表
int IsEmpty(List L);                      //判断链表是否为空
int IsLast(Position p, List L);           //判断节点是否为链表末尾节点

void Insert(int X, List L, Position p);//
void Delete(int X, List L);
Position Find(int X, List L);
Position FindKth(int K, List L);
Position FindPrevious(int X, List L);

int Length(List L);
int getIndex(Position p, List L);
int Retrieve(Position p);

void PrintList(List L); //打印链表
void PrintList_recursion(List L);
//Position Header(List L);
Position First(List L);
Position Advance(Position p); //前进一个节点

void LinkedListSwap(Position previousNode);

#endif /* _LIST_H */
