#include"Stack.h"
int main()
{
    Stack stack;
    StackInit(&stack);
    StackPush(&stack,0);
    StackPush(&stack,1);
    StackPush(&stack,2);
    StackPush(&stack,3);
    StackPush(&stack,4);
    StackPrint(&stack);
    
    StackPop(&stack);
    StackPrint(&stack);
    printf("栈的长度%d\n", StackLength(&stack));

    StackPop(&stack);
    StackPrint(&stack);
    printf("栈的长度%d\n", StackLength(&stack));

    StackPop(&stack);
    StackPrint(&stack);
    printf("栈的长度%d\n", StackLength(&stack));

    StackPop(&stack);
    StackPrint(&stack);
    printf("栈的长度%d\n", StackLength(&stack));
    StackPop(&stack);
    printf("栈的长度%d\n", StackLength(&stack));






    DestroyStack(&stack);
    return 0;
}