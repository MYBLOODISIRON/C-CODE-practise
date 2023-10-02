#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Datetype;// 可修改顺序表元素类型
typedef struct SeqList
{

    Datetype* element;
    size_t size;
    size_t length;
}List;
void creatlist(List*node,size_t size);// 分配顺序表内存空间并初始化表
void DestroytheList(List*node);// 销毁顺序表
void CheckSeqlistSize(List*node);// 检查表是否已满，若满则扩容顺序表
void ListPrint(List* node);// 打印顺序表数据
void ListPushBack(List*node,Datetype date);// 尾部插入一个元素
void ListpushFront(List*node,Datetype date);// 顺序表头部插入一个元素
void Listinsert(List*node,size_t position,Datetype date);// 给定下标插入一个元素
int IsListEmpty(List*node);// 判断顺序表是否为空
void ListpopFront(List*node);// 顺序表头部删除一个元素
void ListpopBack(List*node);// 顺序表尾部删除一个元素
void ListErase(List*node,size_t position);// 给定下标删除一个元素
void ListSearch(List*node,Datetype date);// 查找元素并打印下标