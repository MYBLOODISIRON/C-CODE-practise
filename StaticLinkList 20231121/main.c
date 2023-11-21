#include"library.h"
int main()
{
    StaticList list;
    ListInit(&list,10);
    ListInsert(&list,1,1);
    ListPrint(&list);
    ListInsert(&list,2,1);
    ListPrint(&list);
    ListInsert(&list,3,3);
    ListPrint(&list);
    ListInsert(&list,4,1);
    ListPrint(&list);
    ListInsert(&list,5,1);
    ListPrint(&list);
    ListInsert(&list,6,1);
    ListPrint(&list);
    ListInsert(&list,7,1);
    ListPrint(&list);
    ListInsert(&list,8,1);
    ListPrint(&list);
    ListInsert(&list,9,1);
    ListPrint(&list);
    ListInsert(&list,10,10);
    ListPrint(&list);


    ListErase(&list,5);
    ListPrint(&list);
    ListInsert(&list,11,5);
    ListPrint(&list);
    printf("%2d\n",ListGetPosition(&list,4));
    ListModify(&list,20,9);
    ListPrint(&list);
    printf("%2d\n",ListSearch(&list,8,1));
    ListErase(&list,1);
    printf("%2d\n", ListGetPosition(&list,9));



    DestroyList(&list);
    return 0;
}