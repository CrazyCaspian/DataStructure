#include"list.h"
#include<stdio.h>
#include"fatal.h"
#include<stdlib.h>
#define  ElementType int
struct Node
{
    ElementType Element;
    Position Next;
};
/*创建一个空表*/
List MakeEmpty()
{
    List L;
    L = malloc(sizeof(struct Node));
    if(L == NULL)
        FatalError("Can't create a List");
    return L;
}
/*返回一个空表*/
int IsEmpty(List L)
{
    return L->Next == NULL;
}

/*测试当前位置是否为链表的末尾*/
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

/*找到元素x的位置*/
Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while(P != NULL && P->Element != X)
        P = P->Next;
    return P;
}

/*链表删除*/
void Delete(ElementType X, List L)
{
    Position P,TmpCell;

    P= FindPrevious(X, L);

    if(!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/*返回上一个元素*/
Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;

    while(P->Next != NULL && P->Next->Element != X)
        P = P->Next;

    return P;
}

/*链表的插入*/
void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        FatalError("Out of space!!");

    TmpCell->Element = X;
    TmpCell->Next =  P->Next;
    P->Next = TmpCell;
}
