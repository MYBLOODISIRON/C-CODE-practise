#include"library.h"
void QueueInit(Queue*queue)
{
    assert(queue);
    queue->head=queue->tail=NULL;

}


void DestroyQueue(Queue*queue)
{
    assert(queue);
    QueueNode*current=queue->head;
    while(current)
    {
        QueueNode*next=current->next;
        free(current);
        current=next;
    }
    queue->head=queue->tail=NULL;
}


QueueNode*AllocateQueueNode(QueueDataType data)
{
    QueueNode*new_node=(QueueNode*)malloc(sizeof(QueueDataType));
    if(new_node==NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}


void QueuePush(Queue*queue,QueueDataType data)
{
    assert(queue);
    if(queue->head==NULL)
    {
        queue->head=queue->tail= AllocateQueueNode(data);
    }
    else
    {
        QueueNode*tail=queue->tail;
        queue->tail=AllocateQueueNode(data);
        tail->next=queue->tail;
    }
}


void QueuePop(Queue*queue)
{
    assert(queue);
    assert(queue->head);

    QueueNode*next=queue->head->next;
    free(queue->head);
    queue->head=next;
    if(queue->head==NULL)
    {
        queue->tail=NULL;
    }
}