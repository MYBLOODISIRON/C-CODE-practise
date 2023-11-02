#include"CircularQueue.h"
void PrintCircularQueue(CircularQueue*queue)// ��ӡ�����е�Ԫ��
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

QueueNode* AllocateQueueNode()// ����һ�����
{
    QueueNode*new_node=(QueueNode*)malloc(sizeof(QueueNode));
     if(new_node==NULL)
    {
        perror("node malloc failed");
        exit(-1);
    }
     return new_node;
}



void CircularQueueInit(CircularQueue*queue)// ��ʼ��ѭ������
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


void DestroyCircularQueue(CircularQueue*queue)// �ݻ�ѭ������
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


bool IsQueueFull(CircularQueue*queue)// �ж϶����Ƿ�����
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


void CircularQueuePush(CircularQueue*queue,DataType data)// �������
{
    assert(queue);
    assert(!IsQueueFull(queue));
    queue->rear->data=data;
    queue->rear=queue->rear->next;
}


bool IsQueueEmpty(CircularQueue*queue)// �ж϶����Ƿ��ѿ�
{
    assert(queue);
    if(queue->front==queue->rear)
        return true;
    else
        return false;
}


DataType CircularQueuePop(CircularQueue*queue)// ���ݳ��ӣ������س��ӵ�����
{
    assert(queue);
    assert(!IsQueueEmpty(queue));
    DataType data=queue->front->data;
    queue->front=queue->front->next;
    return data;
}


size_t CircularQueueLen(CircularQueue*queue)// ���ض��еĳ���
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