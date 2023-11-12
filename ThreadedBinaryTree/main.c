#include"library.h"
int main()
{
    srand(0);
    TreeNode*root=NULL;
    for(int i=0;i<5;i++)
    {
        root=TreeInsert(root,rand()%100);
    }

    BuildThreadedBinaryTree(root);
    TreePreorderTraversal(root);
    printf("\n");
    TreeTraversalAfterThreading(root);

    DestroyTree(root);
    root=NULL;
    return 0;
}