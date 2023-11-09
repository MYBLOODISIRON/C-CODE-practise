#include"Stack.h"
void StackPrint(Stack*stack)// 打印栈元素
{
    assert(stack);
    for(int i=0;i<=stack->top;i++)
    {
        printf(PRINT_FORMAT" ",stack->data[i]);
    }
    printf("\n");
    if(IsStackEmpty(stack))
    {
        printf("stack is empty\n");
    }
}


void StackInit(Stack*stack)// 对栈进行初始化
{
    assert(stack);
    stack-> data=NULL;
    stack->size=0;
    stack->top=-1;
}


void DestroyStack(Stack*stack)// 摧毁栈
{
    assert(stack);
    free(stack->data);
    stack->data=NULL;
    stack->top=-1;
    stack->size=0;

}


void IsStackFull(Stack*stack)// 判断栈是否已满，若满则扩容
{
    assert(stack);
    if(stack->size==stack->top+1)
    {
        int new_size= stack->size>0?(stack->size)*2:2;
        DataType*new_data=(DataType*)realloc(stack->data,sizeof(DataType)*new_size);
        if(new_data==NULL)
        {
            perror(" reallocate failed");
            exit(-1);
        }
        stack->data=new_data;
        stack->size=new_size;
    }
}


void StackPush(Stack*stack,DataType data)// 数据入栈
{
    assert(stack);
    IsStackFull(stack);
    stack->data[stack->top+1]=data;
    stack->top++;
}


bool IsStackEmpty(Stack*stack)// 判断栈是否已空
{
    assert(stack);
    if(stack->top==-1)
        return true;
    else
        return false;
}


DataType StackPop(Stack*stack)// 数据出栈，并返回出栈的数据
{
    assert(stack);
    assert(stack->top!=-1);
    DataType data=stack->data[stack->top];
    stack->top--;
    return data;
}


int StackLength(Stack*stack)// 计算并返回栈的长度
{
    return stack->top+1;
}


DataType StackTop(Stack*stack)
{
    return stack->data[stack->top];
}



void YesOrNo(int stack_size,int element_num,DataType*stack_order)
//stack_size:栈最大容量;
// element_num:入栈元素个数;
// stack_order:入栈顺序数组
{
    Stack stack;
    StackInit(&stack);


    DataType* element=(DataType*)malloc(sizeof(DataType)*element_num);
    // 指向出栈序列的指针
    for(int i=0;i<element_num;i++)
    {
        scanf(SCAN_FORMAT,element+i);
    }

    int i=0;// 栈元素下标
    int j=0;// 序列下标
    while(true)
    {
        if(i==element_num|| StackLength(&stack)==stack_size)break;
        StackPush(&stack,stack_order[i]);
        while(StackTop(&stack)==element[j])
        {
            j++;
            StackPop(&stack);
        }
        i++;
        if(j==element_num)
        {
            printf("yes\n");
            return ;
        }
    }
    printf("no\n");

    DestroyStack(&stack);
    free(element);
}