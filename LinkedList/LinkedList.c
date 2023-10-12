#include"LinkedList.h"
void ListPrint(Node*head)// ��ӡ����
{
    assert(head);
    Node*cur=head->next;
    while(cur!=head)
    {
        printf("%d ",cur->date);
        cur=cur->next;
    }
    if(head->next==head)
    {
        printf("�����ѿ�");
    }
    printf("\n");
}



Node* ListInit(Node*head)// ��ʼ������
{
    head=(Node*)malloc(sizeof(Node));
    if(head==NULL)
    {
        perror("malloc headnode failed");
        exit(-1);
    }
    head->next=head;
    head->prev=head;
    return head;
}



void ListDestroy(Node*head)// �ݻ�����
{
    assert(head);
    Node*cur=head->next;
    while(cur!=head)
    {
        Node*next=cur->next;
        free(cur);
        cur=next;
    }
    free(head);
    head=NULL;
}



Node* BuyListNode(DateType date)// ����һ�����Ŀռ�
{
    Node*node= (Node*)malloc(sizeof(Node));
    if(node==NULL)
    {
        perror("malloc node failed");
        exit(-1);
    }
    node->date=date;
    node->prev=NULL;
    node->next=NULL;
    return node;
}



void ListInsert(Node*head,Node*position,DateType date)// ��position��ָ��Ľ��������һ��Ԫ��
{
    assert(head);
    Node*new_node=BuyListNode(date);
    Node*next=position->next;
    next->prev=new_node;
    new_node->next=next;
    position->next=new_node;
    new_node->prev=position;

}



void ListPushBack(Node*head,DateType date)//�������β������һ��Ԫ��
{
    assert(head);
    ListInsert(head,head->prev,date);
}


void ListPushFront(Node*head,DateType date)// �������ͷ������һ��Ԫ��
{
    assert(head);
    ListInsert(head,head,date);
}



void ListErase(Node*head,Node*position)// ɾ��position��ָ��Ľ��
{
    assert(position);
    assert(head->next!=head);
    assert(head!=position);
    Node*prev=position->prev;
    Node*next=position->next;
    free(position);
    prev->next=next;
    next->prev=prev;
}



void ListPopBack(Node*head)// ɾ������β����Ԫ��
{
    assert(head);
    assert(head->next!=head);
    ListErase(head,head->prev);
}



void ListPopFront(Node*head)// ɾ������ͷ����Ԫ��
{
    assert(head);
    assert(head->next!=head);
    ListErase(head,head->next);
}



Node*ListFind(Node*head,DateType date)// ����Ԫ�ز����ظ�Ԫ�صĵ�ַ
{
    assert(head);
    Node*ptr=head->next;
    while(ptr!=head)
    {
        if(ptr->date==date)
        {
            return ptr;
        }
        ptr=ptr->next;
    }

    return NULL;
}


void ListModify(Node*position,DateType date)// �޸�position��ָ��Ľ���Ԫ��
{
    assert(position);
    position->date=date;
}