#pragma once
#define PRINT_FORMAT "%2d"
typedef int DataType;
typedef struct StaticListNode
{
    DataType data;
    int cursor;
}StaticListNode;
typedef struct StaticList
{
    StaticListNode*nodes;
    int size;// 存储数据的最大容量
    int length;// 当前元素的数量
}StaticList;
void ListInit(StaticList*list,int size);// 初始化静态链表
void DestroyList(StaticList*list); // 摧毁静态链表

bool IsListFull(StaticList*list);// 判断静态链表是否已满
void ListInsert(StaticList*list,DataType data,int position);// 指定位置插入元素，链表节点的逻辑位置position是从1开始
void ListPushFront(StaticList*list);// 在静态链表头部插入元素
void ListPoshBack(StaticList*list);// 在静态链表尾部插入元素

bool IsListEmpty(StaticList*list);// 判断静态链表是否为空
void ListErase(StaticList*list,int position);// 删除指定位置的元素
void ListPopFront(StaticList*list);// 删除静态链表头部元素
void ListPopBack(StaticList*list);// 删除静态链表尾部元素

int ListSearch(StaticList*list,DataType data,int count);// 查找给定元素并返回第个count该元素的位置，不存在则返回0
int ListGetIndex(StaticList*list,int position);// 查找给定的位置并返回该元素数组下标
int ListGetPosition(StaticList*list,int index);//查找并返回数组下标index处元素的位置,不存在返回0

void ListModify(StaticList*list,DataType data,int position);// 修改position处的元素


void ListPrint(StaticList*list);// 打印静态链表元素