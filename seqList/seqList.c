#include "seqList.h"

void creatlist(List*plist,size_t size)// 分配顺序表内存空间并初始化表
{
    assert(plist);
    if(size==0)
    {
        size=1;
    }
    plist->element =(Datetype*)malloc(sizeof(Datetype)*size);
    if(plist==NULL)
    {
        perror("创建顺序表失败");
        exit(-1);
    }
    plist->size=size;
    plist->length=0;
}



void DestroytheList(List*plist)// 销毁顺序表
{
    free(plist->element);
    plist->element=NULL;
    plist->length=0;
    plist->size=0;
}



void CheckSeqlistSize(List*plist)// 检查表是否已满，若满则扩容顺序表
{
    if(plist->size==plist->length)
    {
        size_t newsize=2*plist->size;
        Datetype*newelement=(Datetype*)realloc(plist->element,newsize*sizeof(Datetype));
    if(newelement==NULL)
    {
        perror("分配内存失败");
        exit(-1);
    }
    plist->size=newsize;
    plist->element = newelement;

    }
}



void ListPrint(List* plist)// 打印顺序表数据
{
    if(IsListEmpty(plist))
    {
        for (size_t i = 0; i < plist->length; i++)
        {
            printf("%d ", plist->element[i]);
        }
        printf("\n");
    }
    else printf("List is empty\n");
}



void ListPushBack(List*plist,Datetype date)// 顺序表尾部插入一个元素
{
    CheckSeqlistSize(plist);
    plist->element[plist->length]=date;
    plist->length++;
}



void ListpushFront(List*plist,Datetype date)// 顺序表头部插入一个元素
{
    CheckSeqlistSize(plist);
    size_t tag=plist->length;
    while(tag)
    {
        plist->element[tag]=plist->element[tag-1];
        tag--;
    }
    plist->element[0]=date;
    plist->length++;
}



void Listinsert(List*plist,size_t position,Datetype date)// 给定下标插入一个元素
{
    CheckSeqlistSize(plist);
    if(position<=plist->length)
    {
        for(size_t tag=plist->length;tag>position;tag--)
        {
            plist->element[tag]=plist->element[tag-1];
        }
        plist->element[position]=date;
        plist->length++;
    }
    //else if(position==0) ListpushFront(node,date);
    //else if(position==node->length) ListPushBack(node,date);
    else
    {
        printf("请输入合法的元素插入位置\n");
    }
}



int IsListEmpty(List*plist)// 判断顺序表是否为空
{
    if(plist->length==0) return 0;
    else return 1;
}



void ListpopFront(List*plist)// 顺序表头部删除一个元素
{
   if(IsListEmpty(plist))// 确保顺序表不为空表
   {
       for(size_t tag=1;tag<plist->length;tag++)
       {
           plist->element[tag-1]=plist->element[tag];
       }
       plist->length--;
   }
}



void ListpopBack(List*plist)// 顺序表尾部删除一个元素
{

    if(IsListEmpty(plist))// 确保顺序表不为空表
    plist->length--;
}



void ListErase(List*plist,size_t position)// 给定下标删除一个元素
{
    if(IsListEmpty(plist))
    {
        if(position<plist->length)
        {
            for(size_t tag=position;tag<plist->length-1;tag++)
            {
                plist->element[tag]=plist->element[tag+1];
            }
            plist->length--;
        }
        else
        {
            printf("请输入合法的元素删除位置\n");
        }
    }

}



void ListSearch(List*plist,Datetype date)// 打印给定元素在顺序表中的下标
{
    int flag=0;
    for(size_t tag=0;tag<plist->length;tag++)
    {
        if(plist->element[tag]==date)
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



void ListModify(List*plist,size_t position,Datetype date)// 修改顺序表中的元素
{
    if(position<plist->length)
    {
        plist->element[position]=date;
    }
}