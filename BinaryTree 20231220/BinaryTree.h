#pragma once
#define PRINT_FORMAT "%2d "
typedef int DataType;
typedef struct TreeNode
{
    DataType data;
    struct TreeNode*left,*right;

}TreeNode;
void DestroyTree(TreeNode*root);// 摧毁树
TreeNode*AllocateTreeNode(DataType data);// 分配树的节点
TreeNode* TreeInsert(TreeNode*root,DataType data);// 插入元素
void TreePreorderTraversal(TreeNode*root);// 先序遍历树
void TreeInorderTraversal(TreeNode*root);// 中序遍历树
void TreePostorderTraversal(TreeNode*root);// 后序遍历树
void TreeBreadthFirstSearch(TreeNode*root);// 广度优先搜索

void TreePreorderTraversalNotRecursive(TreeNode*root);// 先序遍历（非递归）
void TreeInorderTraversalNotRecursive(TreeNode*root);// 中序遍历（非递归）
void TreePostorderTraversalNotRecursive(TreeNode*root);// 后序遍历（非递归）