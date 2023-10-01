#include "seqList.h"

void creatlist(List*node,int size)//分配顺序表内存空间并初始化表
{
    assert(node);
    node->element =(Datetype*)malloc(sizeof(Datetype)*size);
    if(node==NULL)
    {
        perror("creatlist failed");
        exit(-1);
    }
    node->size=size;
    node->length=0;
}



void DestroytheList(List*node)//销毁顺序表
{
    free(node->element);
    node->element=NULL;
    node->length=0;
    node->size=0;
}



void CheckSeqlistSize(List*node)//检查表是否已满，若满则扩容顺序表
{
    if(node->size==node->length)
    {
        int newsize=2*node->size;
        Datetype*newelement=(Datetype*)realloc(node->element,newsize*sizeof(Datetype));
    if(newelement==NULL)
    {
        perror("failed");
        exit(-1);
    }
    node->size=newsize;
    node->element = newelement;

    }
}



void ListPushBack(List*node,Datetype date)//尾部插入一个元素
{
    CheckSeqlistSize(node);
    node->element[node->length]=date;
    node->length++;

}



void ListPrint(List* node)//打印顺序表数据
{
    int i = 0;

    for (i = 0; i < node->length; i++)
    {
        printf("%d ", node->element[i]);
    }
    printf("\n");
}



void ListpushFront(List*node,Datetype date)//顺序表头部插入一个元素
{
    CheckSeqlistSize(node);
    int tag=node->length-1;
    while(tag--)
    {
        node->element[tag+1]=node->element[tag];
    }
    node->element[0]=date;
    node->length++;
}



void Listinsert(List*node,size_t position,Datetype date)
{
    CheckSeqlistSize(node);
    if(position>)

}
