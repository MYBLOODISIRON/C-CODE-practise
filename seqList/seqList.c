#include "seqList.h"

void creatlist(List*node,size_t size)// ����˳����ڴ�ռ䲢��ʼ����
{
    assert(node);
    if(size==0)
    {
        size=1;
    }
    node->element =(Datetype*)malloc(sizeof(Datetype)*size);
    if(node==NULL)
    {
        perror("����˳���ʧ��");
        exit(-1);
    }
    node->size=size;
    node->length=0;
}



void DestroytheList(List*node)// ����˳���
{
    free(node->element);
    node->element=NULL;
    node->length=0;
    node->size=0;
}



void CheckSeqlistSize(List*node)// �����Ƿ�����������������˳���
{
    if(node->size==node->length)
    {
        size_t newsize=2*node->size;
        Datetype*newelement=(Datetype*)realloc(node->element,newsize*sizeof(Datetype));
    if(newelement==NULL)
    {
        perror("�����ڴ�ʧ��");
        exit(-1);
    }
    node->size=newsize;
    node->element = newelement;

    }
}



void ListPrint(List* node)// ��ӡ˳�������
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



void ListPushBack(List*node,Datetype date)// ˳���β������һ��Ԫ��
{
    CheckSeqlistSize(node);
    node->element[node->length]=date;
    node->length++;
}



void ListpushFront(List*node,Datetype date)// ˳���ͷ������һ��Ԫ��
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



void Listinsert(List*node,size_t position,Datetype date)// �����±����һ��Ԫ��
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
        printf("������Ϸ���Ԫ�ز���λ��\n");
    }
}



int IsListEmpty(List*node)// �ж�˳����Ƿ�Ϊ��
{
    if(node->length==0) return 0;
    else return 1;
}



void ListpopFront(List*node)// ˳���ͷ��ɾ��һ��Ԫ��
{
   if(IsListEmpty(node))// ȷ��˳���Ϊ�ձ�
   {
       for(size_t tag=1;tag<node->length;tag++)
       {
           node->element[tag-1]=node->element[tag];
       }
       node->length--;
   }
}



void ListpopBack(List*node)// ˳���β��ɾ��һ��Ԫ��
{

    if(IsListEmpty(node))// ȷ��˳���Ϊ�ձ�
    node->length--;
}



void ListErase(List*node,size_t position)// �����±�ɾ��һ��Ԫ��
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
            printf("������Ϸ���Ԫ��ɾ��λ��\n");
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
        printf("��Ԫ�ز�����\n");
    }
}



void ListModify(List*node,size_t position,Datetype date)// �޸�˳����е�Ԫ��
{
    if(position<node->length)
    {
        node->element[position]=date;
    }
}