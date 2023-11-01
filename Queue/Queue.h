#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define PRINT_FORMAT "%-5.1f"
typedef float DataType;
typedef struct QueueNode
{
    DataType data;
    struct QueueNode*next;
}QueueNode;
typedef struct Queue
{
    QueueNode*head;
    QueueNode*tail;
}Queue;
void QueuePrint(Queue*queue);// 打印队列数据
void QueueInit(Queue*queue);// 初始化队列
void DestroyQueue(Queue*queue);// 摧毁队列
QueueNode* BuyQueueNode(DataType data);// 创建一个队列的结点
void QueuePush(Queue*queue,DataType data);// 数据入队
DataType QueuePop(Queue*queue);// 数据出队，并返回出队的数据
size_t QueueLength(Queue*queue);// 返回队列的长度