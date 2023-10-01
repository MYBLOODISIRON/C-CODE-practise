
#include "seqList.h"

int main()
{
    struct SeqList list;
    creatlist(&list,2);
    ListPushBack(&list,20);
    ListPushBack(&list,21);
    ListPushBack(&list,22);
    ListPushBack(&list,23);
    ListPushBack(&list,24);
    ListPrint(&list);


    return 0;
}