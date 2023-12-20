#pragma once
typedef TreeNode* StackDataType;
typedef struct Stack
{
    StackDataType*data;
    int length,top;
}Stack;

void StackInit(Stack*stack);
void DestroyStack(Stack*stack);
void IsStackNeedExpansion(Stack*stack);
void StackPush(Stack*stack,StackDataType data);
void StackPop(Stack*stack);