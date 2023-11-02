#include"CircularQueue.h"
int main()
{
    CircularQueue queue;
    CircularQueueInit(&queue);
    PrintCircularQueue(&queue);
    int x;
    for(x=0;x<20;x++)
    {
        CircularQueuePush(&queue,x);
        PrintCircularQueue(&queue);
        printf("���еĳ���:%zu\n", CircularQueueLen(&queue));

    }
    printf("\n");
    for(x=0;x<20;x++)
    {
        printf("���ӵ�Ԫ��:"PRINT_FORMAT"\n",CircularQueuePop(&queue));
        PrintCircularQueue(&queue);
        printf("���еĳ���:%zu\n", CircularQueueLen(&queue));
        printf("\n");
    }
    



    DestroyCircularQueue(&queue);
    return 0;
}