#include"LinkedList.h"

int main()
{
    Node*head=NULL;
    Node*phead= ListInit(head);
    ListPushBack(phead,1);
    ListPushBack(phead,2);
    ListPushBack(phead,3);
    ListPushBack(phead,4);
    ListPushFront(phead,5);
    ListPushFront(phead,6);
    ListPushFront(phead,7);
    ListPushFront(phead,8);
    ListPushFront(phead,59);
    ListPrint(phead);
    ListPopBack(phead);
    ListPrint(phead);
    ListPopFront(phead);
    ListPrint(phead);
    ListInsert(phead,ListFind(phead,2), 2);
    ListPrint(phead);
    ListErase(phead,ListFind(phead,3));
    ListPrint(phead);



    Node*ptr=phead;
    for(int i=0;i<2;i++)
    {
        ptr=ListFind(ptr,2);
    }
    ListModify(ptr,3);
    ListPrint(phead);






    ListDestroy(phead);
    phead=NULL;

    return 0;
}