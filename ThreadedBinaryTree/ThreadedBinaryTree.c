#include"library.h"

void DestroyTree(TreeNode*root)// 摧毁树
{
    if(root==NULL)return ;
    if(root->left_tag==0)DestroyTree(root->left);
    if(root->right_tag==0)DestroyTree(root->right);
    free(root);
}


TreeNode* AllocateTreeNode(TreeDataType data)// 分配树的节点
{
    TreeNode*new_node=(TreeNode*)malloc(sizeof(TreeNode));
    if(new_node==NULL)
    {
        perror("tree node malloc failed");
        exit(-1);
    }
    new_node->left=new_node->right=NULL;
    new_node->right_tag=new_node->left_tag=0;
    new_node->data=data;
    return new_node;
}


TreeNode* TreeInsert(TreeNode*root,TreeDataType data)// 随即插入树
{
    if(root==NULL)return AllocateTreeNode(data);
    if(rand()%2)
    {
        root->left=TreeInsert(root->left,data);
    }
    else
    {
        root->right=TreeInsert(root->right,data);
    }
    return root;
}


void TreePreorderTraversal(TreeNode*root)
{
    if(root==NULL)
    {
        return ;
    }
    printf( PRINT_FORMAT" ",root->data);
    if(root->left_tag==0)TreePreorderTraversal(root->left);
    if(root->right_tag==0)TreePreorderTraversal(root->right);
}


TreeNode*precursor_node=NULL;
void BuildThreadedBinaryTree(TreeNode*root)// 建立二叉树的先序线索化的
{
    if(root==NULL)return ;
    if(root->left==NULL)
    {
        root->left=precursor_node;
        root->left_tag=1;
    }
    if(precursor_node&&precursor_node->right==NULL)
    {
        precursor_node->right=root;
        precursor_node->right_tag=1;
    }
    precursor_node=root;
    if(root->left_tag==0)BuildThreadedBinaryTree(root->left);
    if(root->right_tag==0)BuildThreadedBinaryTree(root->right);
}


TreeNode* TreeTraversalAfterThreading(TreeNode*root)// 以遍历链表的形式遍历二叉树
{
    TreeNode*current=root;
    while(current)
    {
        printf(PRINT_FORMAT" ",current->data);
       if(current->left_tag==0)
       {
           current=current->left;
       }
       else if(current->left_tag==1)
       {
           current=current->right;
       }
    }
}