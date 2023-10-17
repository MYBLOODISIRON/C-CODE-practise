#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int DataType;
typedef struct Stack
{
    DataType *data;
    int top;
    int size;
}Stack;
void StackPrint(Stack*stack);// 打印栈元素
void StackInit(Stack*stack);// 对栈进行初始化
void DestroyStack(Stack*stack);// 摧毁栈
void IsStackFull(Stack*stack);// 判断栈是否已满，若满则扩容
void StackPush(Stack*stack,DataType data);// 数据入栈
bool IsStackEmpty(Stack*stack);// 判断栈是否已空
DataType StackPop(Stack*stack);// 数据出栈，并返回出栈的数据
int StackLength(Stack*stack);// 计算并返回栈的长度
