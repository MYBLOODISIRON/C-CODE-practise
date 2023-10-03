
#include "seqList.h"

int main()
{
    struct SeqList list;
    creatlist(&list,50);
    ListPushBack(&list,20);
    ListPushBack(&list,21);
    ListPushBack(&list,23);
    ListPushBack(&list,23);
    ListPushBack(&list,22);
    Listinsert(&list,5,22);
    ListPrint(&list);
    ListErase(&list,3);
    ListPrint(&list);
    ListSearch(&list,22);
    ListModify(&list,3,29);
    ListPrint(&list);

    return 0;
}