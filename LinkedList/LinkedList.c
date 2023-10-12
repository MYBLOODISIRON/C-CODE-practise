#include"LinkedList.h"
void ListPrint(Node*head)// 打印链表
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
        printf("链表已空");
    }
    printf("\n");
}



Node* ListInit(Node*head)// 初始化链表
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



void ListDestroy(Node*head)// 摧毁链表
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



Node* BuyListNode(DateType date)// 分配一个结点的空间
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



void ListInsert(Node*head,Node*position,DateType date)// 在position所指向的结点后面插入一个元素
{
    assert(head);
    Node*new_node=BuyListNode(date);
    Node*next=position->next;
    next->prev=new_node;
    new_node->next=next;
    position->next=new_node;
    new_node->prev=position;

}



void ListPushBack(Node*head,DateType date)//在链表的尾部插入一个元素
{
    assert(head);
    ListInsert(head,head->prev,date);
}


void ListPushFront(Node*head,DateType date)// 在链表的头部插入一个元素
{
    assert(head);
    ListInsert(head,head,date);
}



void ListErase(Node*head,Node*position)// 删除position所指向的结点
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



void ListPopBack(Node*head)// 删除链表尾部的元素
{
    assert(head);
    assert(head->next!=head);
    ListErase(head,head->prev);
}



void ListPopFront(Node*head)// 删除链表头部的元素
{
    assert(head);
    assert(head->next!=head);
    ListErase(head,head->next);
}



Node*ListFind(Node*head,DateType date)// 查找元素并返回该元素的地址
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


void ListModify(Node*position,DateType date)// 修改position所指向的结点的元素
{
    assert(position);
    position->date=date;
}