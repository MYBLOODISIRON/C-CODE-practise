#pragma once
#define PRINT_FORMAT "%2d"
typedef int TreeDataType;
typedef struct TreeNode
{
    TreeDataType data;
    struct TreeNode*left, *right;
    int left_tag,right_tag;
}TreeNode;
void DestroyTree(TreeNode*root);// 摧毁树
TreeNode* AllocateTreeNode(TreeDataType data);// 分配树的节点
TreeNode* TreeInsert(TreeNode*root,TreeDataType data);// 插入元素
void BuildThreadedBinaryTree(TreeNode*root);// 建立二叉树的线索化
void TreePreorderTraversal(TreeNode*root);
TreeNode* TreeTraversalAfterThreading(TreeNode*root);// 以遍历链表的形式遍历二叉树