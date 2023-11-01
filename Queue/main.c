#include"Queue.h"
int main()
{
    Queue queue;
    QueueInit(&queue);
    QueuePush(&queue,0);
    QueuePush(&queue,1);
    QueuePush(&queue,2);
    QueuePush(&queue,3);
    QueuePush(&queue,4);
    QueuePrint(&queue);
    printf("队列的长度：%zu\n",QueueLength(&queue));

    QueuePop(&queue);
    QueuePrint(&queue);
    printf("队列的长度：%zu\n",QueueLength(&queue));

    QueuePop(&queue);
    QueuePrint(&queue);
    printf("队列的长度：%zu\n",QueueLength(&queue));

    QueuePop(&queue);
    QueuePrint(&queue);
    printf("队列的长度：%zu\n",QueueLength(&queue));

    QueuePop(&queue);
    QueuePrint(&queue);
    printf("队列的长度：%zu\n",QueueLength(&queue));

    QueuePop(&queue);
    QueuePrint(&queue);
    printf("队列的长度：%zu\n",QueueLength(&queue));





    DestroyQueue(&queue);
    return 0;
}