#include"library.h"

void StackInit(Stack*stack)
{
    assert(stack);
    stack->data=NULL;
    stack->top=-1;
    stack->length=0;
}


void DestroyStack(Stack*stack)
{
    assert(stack);
    if(stack->data)
    {
        free(stack->data);
        stack->data=NULL;
    }
    stack->top=-1;
    stack->length=0;
}


void IsStackNeedExpansion(Stack*stack)
{
    if(stack->length-1==stack->top)
    {
        int new_length= stack->length==0?2:stack->length*2;

        StackDataType*new_stack_data
        =(StackDataType*)realloc(stack->data,sizeof(StackDataType)*new_length);
        if(new_stack_data==NULL)
        {
            perror("stack reallocate failed");
            exit(-1);
        }
        stack->data=new_stack_data;
        stack->length=new_length;
    }
}


void StackPush(Stack*stack,StackDataType data)
{
    assert(stack);
    IsStackNeedExpansion(stack);
    stack->data[++stack->top]=data;
}


void StackPop(Stack*stack)
{
    assert(stack);
    assert(stack->top!=-1);
    stack->top--;
}