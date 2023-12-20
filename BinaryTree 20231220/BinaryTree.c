#include"library.h"

void DestroyTree(TreeNode*root)// ´Ý»ÙÊ÷
{
    if(root==NULL)
    {
        return ;
    }
    DestroyTree(root->left);
    DestroyTree(root->right);
    free(root);
    root=NULL;
}



TreeNode*AllocateTreeNode(DataType data)// ·ÖÅäÊ÷µÄ½Úµã
{
    TreeNode*new_node=(TreeNode*)malloc(sizeof(TreeNode));
    if(new_node==NULL)
    {
        perror("malloc node failed");
        exit(-1);
    }
    new_node->data=data;
    new_node->left=new_node->right=NULL;
    return new_node;
}



TreeNode* TreeInsert(TreeNode*root,DataType data)// Ëæ¼´²åÈëÔªËØ
{
    if(root==NULL) return AllocateTreeNode(data);

    if(rand() % 2)
    {
        root->left=TreeInsert(root->left,data);
    }
    else
    {
        root->right=TreeInsert(root->right,data);
    }
    return root;
}


void TreePreorderTraversal(TreeNode*root)// ÏÈÐò±éÀúÊ÷
{
    if(root==NULL)return;
    printf(PRINT_FORMAT" " ,root->data);
    TreePreorderTraversal(root->left);
    TreePreorderTraversal(root->right);
}


void TreeInorderTraversal(TreeNode*root)// ÖÐÐò±éÀúÊ÷
{
    if(root==NULL)return;
    TreeInorderTraversal(root->left);
    printf(PRINT_FORMAT" ",root->data);
    TreeInorderTraversal(root->right);
}


void TreePostorderTraversal(TreeNode*root)// ºóÐò±éÀúÊ÷
{
    if(root==NULL)return;
    TreePostorderTraversal(root->left);
    TreePostorderTraversal(root->right);
    printf(PRINT_FORMAT" ",root->data);
}


void TreeBreadthFirstSearch(TreeNode*root)// ²ãÐò±éÀúÊ÷
{
    Queue queue;
    QueueInit(&queue);
    if(root)
    {
        QueuePush(&queue,root);
    }
    while(queue.head)
    {
        TreeNode*current=queue.head->data;
        printf(PRINT_FORMAT" ",current->data);

        if(current->left) QueuePush(&queue,current->left);
        if(current->right) QueuePush(&queue,current->right);
        QueuePop(&queue);
    }
    DestroyQueue(&queue);
}

void TreePreorderTraversalNotRecursive(TreeNode*root)// ÏÈÐò±éÀú£¨·ÇµÝ¹é£©
{
    Stack stack;
    StackInit(&stack);
    TreeNode*current_node=root;
    while(current_node||stack.top!=-1)
    {
        if(current_node)
        {
            printf(PRINT_FORMAT" ",current_node->data);
            StackPush(&stack,current_node);
            current_node=current_node->left;
        }
        else
        {
            TreeNode*top=stack.data[stack.top];
            StackPop(&stack);
            current_node=top->right;

        }
    }

    DestroyStack(&stack);
}


void TreeInorderTraversalNotRecursive(TreeNode*root)// ÖÐÐò±éÀú£¨·ÇµÝ¹é£©
{
    Stack stack;
    StackInit(&stack);
    TreeNode*current_node=root;
    while(stack.top!=-1||current_node)
    {
        if(current_node)
        {
            StackPush(&stack,current_node);
            current_node=current_node->left;
        }
        else
        {
            TreeNode*top=stack.data[stack.top];
            printf(PRINT_FORMAT" ",top->data);
            StackPop(&stack);
            current_node=top->right;
        }
    }

    DestroyStack(&stack);
}


