#pragma once
typedef TreeNode* QueueDataType;
typedef struct QueueNode
{
    QueueDataType data;
    struct QueueNode*next;
}QueueNode;
typedef struct Queue
{
    QueueNode*head,*tail;
}Queue;
void QueueInit(Queue*queue);// 初始化队列
void DestroyQueue(Queue*queue);// 摧毁队列
QueueNode*AllocateQueueNode(QueueDataType data);// 分配队列结点
void QueuePush(Queue*queue,QueueDataType data);// 数据入队
void QueuePop(Queue*queue);//数据出队
