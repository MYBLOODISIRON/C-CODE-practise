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
void creatlist(List*plist,size_t size);// 分配顺序表内存空间并初始化表
void DestroytheList(List*plist);// 销毁顺序表
void CheckSeqlistSize(List*plist);// 检查表是否已满，若满则扩容顺序表
void ListPrint(List*plist);// 打印顺序表数据
void ListPushBack(List*plist,Datetype date);// 尾部插入一个元素
void ListpushFront(List*plist,Datetype date);// 顺序表头部插入一个元素
void Listinsert(List*plist,size_t position,Datetype date);// 给定下标插入一个元素
int IsListEmpty(List*plist);// 判断顺序表是否为空
void ListpopFront(List*plist);// 顺序表头部删除一个元素
void ListpopBack(List*plist);// 顺序表尾部删除一个元素
void ListErase(List*plist,size_t position);// 给定下标删除一个元素
void ListSearch(List*plist,Datetype date);// 打印给定元素在顺序表中的下标
void ListModify(List*plist,size_t position,Datetype date);// 修改顺序表中的元素