#include "seqList.h"

void creatlist(List*node,size_t size)// 分配顺序表内存空间并初始化表
{
    assert(node);
    if(size==0)
    {
        size=1;
    }
    node->element =(Datetype*)malloc(sizeof(Datetype)*size);
    if(node==NULL)
    {
        perror("创建顺序表失败");
        exit(-1);
    }
    node->size=size;
    node->length=0;
}



void DestroytheList(List*node)// 销毁顺序表
{
    free(node->element);
    node->element=NULL;
    node->length=0;
    node->size=0;
}



void CheckSeqlistSize(List*node)// 检查表是否已满，若满则扩容顺序表
{
    if(node->size==node->length)
    {
        size_t newsize=2*node->size;
        Datetype*newelement=(Datetype*)realloc(node->element,newsize*sizeof(Datetype));
    if(newelement==NULL)
    {
        perror("分配内存失败");
        exit(-1);
    }
    node->size=newsize;
    node->element = newelement;

    }
}



void ListPrint(List* node)// 打印顺序表数据
{
    if(IsListEmpty(node))
    {
        for (size_t i = 0; i < node->length; i++)
        {
            printf("%d ", node->element[i]);
        }
        printf("\n");
    }
    else printf("List is empty\n");
}



void ListPushBack(List*node,Datetype date)// 顺序表尾部插入一个元素
{
    CheckSeqlistSize(node);
    node->element[node->length]=date;
    node->length++;
}



void ListpushFront(List*node,Datetype date)// 顺序表头部插入一个元素
{
    CheckSeqlistSize(node);
    size_t tag=node->length;
    while(tag)
    {
        node->element[tag]=node->element[tag-1];
        tag--;
    }
    node->element[0]=date;
    node->length++;
}



void Listinsert(List*node,size_t position,Datetype date)// 给定下标插入一个元素
{
    CheckSeqlistSize(node);
    if(position<=node->length)
    {
        for(size_t tag=node->length;tag>position;tag--)
        {
            node->element[tag]=node->element[tag-1];
        }
        node->element[position]=date;
        node->length++;
    }
    //else if(position==0) ListpushFront(node,date);
    //else if(position==node->length) ListPushBack(node,date);
    else
    {
        printf("请输入合法的元素插入位置\n");
    }
}



int IsListEmpty(List*node)// 判断顺序表是否为空
{
    if(node->length==0) return 0;
    else return 1;
}



void ListpopFront(List*node)// 顺序表头部删除一个元素
{
   if(IsListEmpty(node))// 确保顺序表不为空表
   {
       for(size_t tag=1;tag<node->length;tag++)
       {
           node->element[tag-1]=node->element[tag];
       }
       node->length--;
   }
}



void ListpopBack(List*node)// 顺序表尾部删除一个元素
{

    if(IsListEmpty(node))// 确保顺序表不为空表
    node->length--;
}



void ListErase(List*node,size_t position)// 给定下标删除一个元素
{
    if(IsListEmpty(node))
    {
        if(position<node->length)
        {
            for(size_t tag=position;tag<node->length-1;tag++)
            {
                node->element[tag]=node->element[tag+1];
            }
            node->length--;
        }
        else
        {
            printf("请输入合法的元素删除位置\n");
        }
    }

}



void ListSearch(List*node,Datetype date)//
{
    int flag=0;
    for(size_t tag=0;tag<node->length;tag++)
    {
        if(node->element[tag]==date)
        {
            printf("%zu ",tag);
            flag++;
        }

    }
    if(flag>0)
    {
        printf("\n");
    }
    else
    {
        printf("该元素不存在\n");
    }
}



void ListModify(List*node,size_t position,Datetype date)// 修改顺序表中的元素
{
    if(position<node->length)
    {
        node->element[position]=date;
    }
}