#include"library.h"


int main()
{
    TreeNode *root=NULL;
    srand(0);
    for(int i=0;i<5;i++)
    {
        root=TreeInsert(root,rand()%100);
    }
    printf("先序遍历：\n");
    TreePreorderTraversal(root);
    printf("\n");
    printf("先序遍历(非递归)：\n");
    TreePreorderTraversalNotRecursive(root);
    printf("\n");


    printf("中序遍历：\n");
    TreeInorderTraversal(root);
    printf("\n");
    printf("中序遍历(非递归)：\n");
    TreeInorderTraversalNotRecursive(root);
    printf("\n");

    printf("后序遍历：\n");
    TreePostorderTraversal(root);
    printf("\n");
    printf("后序遍历(非递归)：\n");
    TreePostorderTraversalNotRecursive(root);
    printf("\n");


    printf("广度优先搜索：\n");
    TreeBreadthFirstSearch(root);
    printf("\n");



    DestroyTree(root);
    root=NULL;
    return 0;
}