#include"list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    List list = LinkedListCreate();  //2 4 3 6 9 7

    PrintList(list);
    printf("\n");
    PrintList_recursion(list);
    ////������
    //int len = Length(list);
    //printf("list length: %d\n", len);

    //// ����Ԫ��
    //int index = 5;
    //Position p = FindKth(index, list);
    //int elem = Retrieve(p);
    //printf("node value: %d\n", elem);

    ////����Ԫ��
    //int num = 3;
    //Position p2 = Find(num, list);
    //Position p3 = FindPrevious(num, list);
    //int preElem = Retrieve(p3);
    //int re = getIndex(p2, list);
    //printf("node index: %d\npre node value: %d\n", re, preElem);

    ////ɾ��Ԫ��
    //int deleteItem = 3;
    //Delete(deleteItem, list);
    //len = Length(list);
    //printf("list length: %d\n", len);
    //PrintList(list);
    //printf("\n");

    ////����Ԫ��
    //int insertAfter = 2;
    //int insertValue = 11;
    //Position insertP = FindKth(insertAfter, list);
    //Insert(insertValue, list, insertP);

    //len = Length(list);
    //printf("list length: %d\n", len);
    //PrintList(list);
    //printf("\n");

    //DeleteList(list);
    //int IsEmp = IsEmpty(list);
    //printf("empty?: %d\n", IsEmp);
    //len = Length(list);
    //printf("list length: %d\n", len);

    return 0;
}