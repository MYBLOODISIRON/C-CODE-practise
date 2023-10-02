
#include "seqList.h"

int main()
{
    struct SeqList list;
    creatlist(&list,5);
    ListPushBack(&list,20);
    ListPushBack(&list,21);
    ListPushBack(&list,22);
    ListPushBack(&list,23);
    ListPushBack(&list,22);
    Listinsert(&list,5,22);
    ListPrint(&list);
    ListErase(&list,3);
    ListPrint(&list);
    ListSearch(&list,22);



    return 0;
}