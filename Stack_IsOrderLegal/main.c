#include"Stack.h"

int main()
{
    DataType stack_order[20]={1,2,3,4,5,6,7};
    int arr[3];// m n k
    for(int i=0;i<3;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<arr[2];i++)
    {
        YesOrNo(arr[0],arr[1],stack_order);
    }


    return 0;
}