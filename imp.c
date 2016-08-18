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
      // printf("The Cur is %p \n",CuruntP);
       CuruntP->Next = TemCell;
       TemCell->Element = rand()%100+1;
       TemCell->Next = NULL;
       CuruntP = TemCell;
     //  printf("The element in %p is %d \n",CuruntP,CuruntP->Element);
    }
    ShowList(L);
    printf("Let's delete one element,please input a element in list \n");
    int x;
    scanf("%d",&x );
    Delete(x, L);
    ShowList(L);
    printf("Let's find one element,please input a element in list \n");
    scanf("%d",&x );
    Position des;
    des = Find(x, L);
    printf("Let's insert one element,please input a element in list \n");
    scanf("%d", &x);
    Insert(x, L, des);
    ShowList(L);
}

