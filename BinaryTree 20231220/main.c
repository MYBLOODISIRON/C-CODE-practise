#include"library.h"


int main()
{
    TreeNode *root=NULL;
    srand(0);
    for(int i=0;i<5;i++)
    {
        root=TreeInsert(root,rand()%100);
    }
    printf("���������\n");
    TreePreorderTraversal(root);
    printf("\n");
    printf("�������(�ǵݹ�)��\n");
    TreePreorderTraversalNotRecursive(root);
    printf("\n");


    printf("���������\n");
    TreeInorderTraversal(root);
    printf("\n");
    printf("�������(�ǵݹ�)��\n");
    TreeInorderTraversalNotRecursive(root);
    printf("\n");

    printf("���������\n");
    TreePostorderTraversal(root);
    printf("\n");
    printf("�������(�ǵݹ�)��\n");
    TreePostorderTraversalNotRecursive(root);
    printf("\n");


    printf("�������������\n");
    TreeBreadthFirstSearch(root);
    printf("\n");



    DestroyTree(root);
    root=NULL;
    return 0;
}