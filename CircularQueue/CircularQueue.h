#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#define QUEUE_SIZE (20+1)
#define PRINT_FORMAT "%2d "
typedef int DataType;
typedef struct QueueNode
{
    struct QueueNode*next;
    DataType data;
}QueueNode;
typedef struct CircularQueue
{
    QueueNode*front;
    QueueNode*rear;
}CircularQueue;
void PrintCircularQueue(CircularQueue*queue);// 打印队列中的元素
QueueNode* AllocateQueueNode();// 分配一个结点
void CircularQueueInit(CircularQueue*queue);// 初始化循环队列
void DestroyCircularQueue(CircularQueue*queue);// 摧毁循环队列
bool IsQueueFull(CircularQueue*queue);// 判断队列是否已满
void CircularQueuePush(CircularQueue*queue,DataType data);// 数据入队
bool IsQueueEmpty(CircularQueue*queue);// 判断队列是否已空
DataType CircularQueuePop(CircularQueue*queue);// 数据出队，并返回出队的数据
size_t CircularQueueLen(CircularQueue*queue);// 返回队列的长度
