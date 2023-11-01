#include"Queue.h"
void QueuePrint(Queue*queue)// 打印队列数据
{
    assert(queue);
    if(queue->head)
    {
        QueueNode*current=queue->head;
        while(current)
        {
            printf(PRINT_FORMAT,current->data);
            current=current->next;
        }
        printf("\n");
    }
    else
    {
        printf("queue is empty\n");
    }

}


void QueueInit(Queue*queue)// 初始化队列
{
    assert(queue);
    queue->head=NULL;
    queue->tail=NULL;
}


void DestroyQueue(Queue*queue)// 摧毁队列
{
    assert(queue);
    QueueNode*current=queue->head;
    while(current)
    {
        QueueNode*next=current->next;
        free(current);
        current=next;
    }
    queue->head=NULL;
    queue->tail=NULL;
}


QueueNode* BuyQueueNode(DataType data)// 创建一个队列的结点
{
    QueueNode*new_node=(QueueNode*)malloc(sizeof(QueueNode));
    if(new_node==NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}


void QueuePush(Queue*queue,DataType data)// 数据入队
{
    assert(queue);
    if(queue->head!=NULL)
    {
        QueueNode*tail=queue->tail;
        tail->next=BuyQueueNode(data);
        queue->tail=tail->next;
    }
    else
    {
        queue->head=queue->tail=BuyQueueNode(data);
    }
}


DataType QueuePop(Queue*queue)// 数据出队，并返回出队的数据
{
    assert(queue);
    assert(queue->head);

    QueueNode*head=queue->head;
    DataType data=head->data;

    queue->head=head->next;
    free(head);
    head=NULL;
    if(queue->head==NULL)
    {
        queue->tail=queue->head;
    }
    return data;
}


size_t QueueLength(Queue*queue)// 返回队列的长度
{
    assert(queue);
    size_t count=0;
    QueueNode*current=queue->head;
    while(current)
    {
        count++;
        current=current->next;
    }
    return count;
}