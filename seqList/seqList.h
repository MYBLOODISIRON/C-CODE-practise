#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Datetype;
typedef struct SeqList
{

    Datetype* element;
    int size;
    int length;
}List;
void creatlist(List*node,int size);// 分配顺序表内存空间并初始化表
void DestroytheList(List*node);// 销毁顺序表
void CheckSeqlistSize(List*node);// 检查表是否已满，若满则扩容顺序表
void ListPushBack(List*node,Datetype date);// 尾部插入一个元素
void ListPrint(List* node);// 打印顺序表元素
void ListpushFront(List*node,Datetype date);// 顺序表头部插入一个元素