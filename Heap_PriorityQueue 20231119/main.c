#include"library.h"

int main()
{
    srand(0);
    Heap heap;
    HeapInit(&heap,20);
    for(int i=0;i<10;i++)
    {
        HeapPush(&heap,rand()%100);
    }
    HeapPrint(&heap);

    for(int j=0;j<10;j++)
    {
        HeapPop(&heap);
        HeapPrint(&heap);
    }
    DestroyHeap(&heap);
    return 0;
}
