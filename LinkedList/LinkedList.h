#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DateType;
typedef struct LinkedListNode
{
    DateType date;
    struct LinkedListNode* next;
    struct LinkedListNode*prev;

}Node;
void ListPrint(Node*head);// 打印链表
Node* ListInit(Node*head);// 初始化链表
void ListDestroy(Node*head);// 摧毁链表
Node*BuyListNode(DateType date);// 分配一个结点的空间
void ListInsert(Node*head,Node*position,DateType date);// 在position所指向的结点后面插入一个元素
void ListPushBack(Node*head,DateType date);//在链表的尾部插入一个元素
void ListPushFront(Node*head,DateType date);// 在链表的头部插入一个元素
void ListErase(Node*head,Node*position);// 删除position所指向的结点
void ListPopBack(Node*head);// 删除链表尾部的元素
void ListPopFront(Node*head);// 删除链表头部的元素
Node*ListFind(Node*head,DateType date);// 查找元素并返回该元素的地址
void ListModify(Node*position,DateType date);// 修改position所指向的结点的元素