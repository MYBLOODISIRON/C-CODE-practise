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
        printf("队列的长度:%zu\n", CircularQueueLen(&queue));

    }
    printf("\n");
    for(x=0;x<20;x++)
    {
        printf("出队的元素:"PRINT_FORMAT"\n",CircularQueuePop(&queue));
        PrintCircularQueue(&queue);
        printf("队列的长度:%zu\n", CircularQueueLen(&queue));
        printf("\n");
    }
    



    DestroyCircularQueue(&queue);
    return 0;
}