#include"library.h"
void ListInit(StaticList*list,int size)// 初始化静态链表
{
    assert(list);
    assert(size>0);
    StaticListNode*nodes=(StaticListNode*)malloc(sizeof(StaticListNode)*(size+2));
    if(nodes==NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    list->nodes=nodes;
    list->size=size;
    list->length=0;

    int current=0;
    while(current<size)
    {
        nodes[current].cursor=current+1;
        current++;
    }
    nodes[current].cursor=0;
    nodes[list->size+1].cursor=0;
}

void DestroyList(StaticList*list) // 摧毁静态链表
{
    assert(list);
    free(list->nodes);
    list->nodes=NULL;
    list->size=0;
    list->length=0;
}

bool IsListFull(StaticList*list)// 判断静态链表是否已满
{
    assert(list);
    return list->nodes[0].cursor==0;
}

void ListInsert(StaticList*list,DataType data,int position)// 指定位置插入元素，链表节点的逻辑位置position从1开始
{
    assert(!IsListFull(list));
    assert(position>0&&position<=list->length+1);


    int new_node_cursor=list->nodes[0].cursor;
    list->nodes[0].cursor=list->nodes[new_node_cursor].cursor;
    list->nodes[new_node_cursor].data=data;

    int pre_cursor=ListGetIndex(list,position-1);
    // 找到要插入位置的前一位下标

    list->nodes[new_node_cursor].cursor=list->nodes[pre_cursor].cursor;
    list->nodes[pre_cursor].cursor=new_node_cursor;
    list->length++;
}

bool IsListEmpty(StaticList*list)// 判断静态链表是否为空
{
    assert(list);
    return list->nodes[list->size+1].cursor==0;
}

void ListErase(StaticList*list,int position)// 删除指定位置的元素
{
    assert(!IsListEmpty(list));
    assert(position>0&&position<=list->length);
    int pre_cursor= ListGetIndex(list,position-1);

    int current_cursor=list->nodes[pre_cursor].cursor;
    list->nodes[pre_cursor].cursor=list->nodes[current_cursor].cursor;

    list->nodes[current_cursor].cursor=list->nodes[0].cursor;
    list->nodes[0].cursor=current_cursor;
    list->length--;

}

int ListSearch(StaticList*list,DataType data,int count)// 查找给定元素并返回第count个该元素的位置，不存在则返回0
{
    assert(list);
    assert(count>0);
    int current_cursor=list->nodes[list->size+1].cursor;
    while(current_cursor)
    {

        if(list->nodes[current_cursor].data==data)
        {
            count--;
        }
        if(count==0)
        {
            return ListGetPosition(list,current_cursor);
        }
        current_cursor=list->nodes[current_cursor].cursor;
    }
    return 0;
}

int ListGetIndex(StaticList*list,int position)// 查找给定的位置并返回该元素数组下标
{
    assert(list);
    assert(position >=0 && position <= list->length);
    int cursor=list->size+1;
    for (int step = 0; step < position; step++)
    {
        cursor=list->nodes[cursor].cursor;
    }
    return cursor;
}

int ListGetPosition(StaticList*list,int index)// 查找并返回数组下标index元素的位置,不存在返回0
{
    assert(list);
    assert(index>0&&index<=list->size);
    int cursor=list->size+1;
    int position=0;
    while(cursor)
    {
        if(cursor==index)return position;
        cursor=list->nodes[cursor].cursor;
        position++;
    }
    return 0;
}

void ListModify(StaticList*list,DataType data,int position)// 修改position处的元素
{
    assert(list);
    assert(position>0&&position<=list->length);
    int index=ListGetIndex(list,position);
    list->nodes[index].data=data;
}

void ListPrint(StaticList*list)// 打印静态链表元素
{
    assert(list);
    int cursor=list->nodes[list->size+1].cursor;
    if(cursor==0)
    {
        printf("list is empty");
    }
    while(cursor)
    {
        printf(PRINT_FORMAT" ",list->nodes[cursor].data);
        cursor=list->nodes[cursor].cursor;
    }
    printf("\n");
}