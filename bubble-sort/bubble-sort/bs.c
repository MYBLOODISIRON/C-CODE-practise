#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����ð������
//void bubble_sort(int* arr,int sz)
//{
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//			flag = 1;
//
//		}
//		if (flag == 0)break;
//	}
//	
//}
//�ص�����ʵ��ð������
void swap(char*e1,char*e2,int width)//����Ԫ��
{
	
	for (int flag=0;flag<width;flag++ )
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
		
	}
}
int cmp(const void* e1,const void*e2)
{
	return *((int*)e1) - *((int* )e2);//�������򣨷���ֵ>0ʱ���н���Ԫ�أ�//�������� *((int*)e2) - *((int* )e1)
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void*, const void*)) 
{
	char* Base = (char*)base;
	int i = 0, j = 0;
	int flag = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if(cmp((Base + j * width), (Base + (j + 1) * width))>0)
			swap((Base+j*width),(Base+(j+1)*width), width);
			flag = 1;
		}
		if (flag == 0)break;
	}
}
int main()
{

	int arr[] = {10,6,3,8,5,7,12,110};
	int sz = sizeof(arr) / sizeof(arr[0]);//Ԫ�ظ���
	int width = sizeof(arr[0]);//Ԫ�ش�С
	//bubble_sort(arr, sz);
	bubble_sort(arr, sz, width, cmp);
	for (int num = 0; num < sz; num++)
	{
		printf("%d ", arr[num]);
	}




	return 0;
}
//ͨ��cmp�ı亯���ڲ���ָ�����Ϳ��Խ��κ����͵�Ԫ�ؽ�������



