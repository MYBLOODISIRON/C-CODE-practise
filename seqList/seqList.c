#include "seqList.h"

void creatlist(List*plist,size_t size)// ����˳����ڴ�ռ䲢��ʼ����
{
    assert(plist);
    if(size==0)
    {
        size=1;
    }
    plist->element =(Datetype*)malloc(sizeof(Datetype)*size);
    if(plist==NULL)
    {
        perror("����˳���ʧ��");
        exit(-1);
    }
    plist->size=size;
    plist->length=0;
}



void DestroytheList(List*plist)// ����˳���
{
    free(plist->element);
    plist->element=NULL;
    plist->length=0;
    plist->size=0;
}



void CheckSeqlistSize(List*plist)// �����Ƿ�����������������˳���
{
    if(plist->size==plist->length)
    {
        size_t newsize=2*plist->size;
        Datetype*newelement=(Datetype*)realloc(plist->element,newsize*sizeof(Datetype));
    if(newelement==NULL)
    {
        perror("�����ڴ�ʧ��");
        exit(-1);
    }
    plist->size=newsize;
    plist->element = newelement;

    }
}



void ListPrint(List* plist)// ��ӡ˳�������
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



void ListPushBack(List*plist,Datetype date)// ˳���β������һ��Ԫ��
{
    CheckSeqlistSize(plist);
    plist->element[plist->length]=date;
    plist->length++;
}



void ListpushFront(List*plist,Datetype date)// ˳���ͷ������һ��Ԫ��
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



void Listinsert(List*plist,size_t position,Datetype date)// �����±����һ��Ԫ��
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
        printf("������Ϸ���Ԫ�ز���λ��\n");
    }
}



int IsListEmpty(List*plist)// �ж�˳����Ƿ�Ϊ��
{
    if(plist->length==0) return 0;
    else return 1;
}



void ListpopFront(List*plist)// ˳���ͷ��ɾ��һ��Ԫ��
{
   if(IsListEmpty(plist))// ȷ��˳���Ϊ�ձ�
   {
       for(size_t tag=1;tag<plist->length;tag++)
       {
           plist->element[tag-1]=plist->element[tag];
       }
       plist->length--;
   }
}



void ListpopBack(List*plist)// ˳���β��ɾ��һ��Ԫ��
{

    if(IsListEmpty(plist))// ȷ��˳���Ϊ�ձ�
    plist->length--;
}



void ListErase(List*plist,size_t position)// �����±�ɾ��һ��Ԫ��
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
            printf("������Ϸ���Ԫ��ɾ��λ��\n");
        }
    }

}



void ListSearch(List*plist,Datetype date)// ��ӡ����Ԫ����˳����е��±�
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
        printf("��Ԫ�ز�����\n");
    }
}



void ListModify(List*plist,size_t position,Datetype date)// �޸�˳����е�Ԫ��
{
    if(position<plist->length)
    {
        plist->element[position]=date;
    }
}