#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"
#include"fatal.h"
struct Node
{
    ElementType Element;
    Position Next;
};
void main()
{
    List L;
    L = MakeEmpty();
    Position CuruntP = L;
    Position TemCell;
    int i, num;
    srand(time(NULL));
    for(i=0;i<10;i++)
    {
       TemCell = malloc(sizeof(struct Node));
       if(TemCell == NULL)
           FatalError("OUt of space!");
       CuruntP->Next = TemCell;
       TemCell->Element = rand()%100+1;
       TemCell->Next = NULL;
       CuruntP =  TemCell;
       printf("The element is %d\n", CuruntP->Element);
    }
}

