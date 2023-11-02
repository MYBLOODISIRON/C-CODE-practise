#include"CircularQueue.h"
void PrintCircularQueue(CircularQueue*queue)// 打印队列中的元素
{
    assert(queue);
    if(IsQueueEmpty(queue))
    {
        printf("queue is empty\n");
    }
    else
    {
        QueueNode* current=queue->front;
        while(current!=queue->rear)
        {
            printf(PRINT_FORMAT" ",current->data);
            current=current->next;
        }
        printf("\n");
    }
}

QueueNode* AllocateQueueNode()// 分配一个结点
{
    QueueNode*new_node=(QueueNode*)malloc(sizeof(QueueNode));
     if(new_node==NULL)
    {
        perror("node malloc failed");
        exit(-1);
    }
     return new_node;
}



void CircularQueueInit(CircularQueue*queue)// 初始化循环队列
{
    assert(queue);
    QueueNode*current=queue->front=queue->rear=AllocateQueueNode();
    for(int x=0;x<QUEUE_SIZE-1;x++)
    {
       current->next=AllocateQueueNode();
       current=current->next;
    }
    current->next=queue->front;
}


void DestroyCircularQueue(CircularQueue*queue)// 摧毁循环队列
{
    assert(queue);
    QueueNode*current=queue->front;
    for(int x=0;x<QUEUE_SIZE;x++)
    {
        QueueNode*next=current->next;
        free(current);
        current=next;
    }
    queue->front=queue->rear=NULL;
}


bool IsQueueFull(CircularQueue*queue)// 判断队列是否已满
{
    assert(queue);
    if(queue->rear->next==queue->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void CircularQueuePush(CircularQueue*queue,DataType data)// 数据入队
{
    assert(queue);
    assert(!IsQueueFull(queue));
    queue->rear->data=data;
    queue->rear=queue->rear->next;
}


bool IsQueueEmpty(CircularQueue*queue)// 判断队列是否已空
{
    assert(queue);
    if(queue->front==queue->rear)
        return true;
    else
        return false;
}


DataType CircularQueuePop(CircularQueue*queue)// 数据出队，并返回出队的数据
{
    assert(queue);
    assert(!IsQueueEmpty(queue));
    DataType data=queue->front->data;
    queue->front=queue->front->next;
    return data;
}


size_t CircularQueueLen(CircularQueue*queue)// 返回队列的长度
{
    size_t count=0;
    QueueNode*current=queue->front;
    while(current!=queue->rear)
    {
        count++;
        current=current->next;
    }
    return count;
}