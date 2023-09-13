#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void* my_memmove(void* dest,const void *src,int width)// memmove函数用于对自身的拷贝
// width 表示需要拷贝的字节数
{
	assert(dest && src);// 断言dest和src是否全不为NULL
	void* ret = dest;
	if (dest > src)// dest大于src时，从前往后拷贝不会造成数据的覆盖
	{
		while (width--)
		{
			*(char*) dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else if (dest < src)// src大于dest时，从后往前拷贝不会对造成覆盖数据
	{
		while (width--)
		{
			*((char*)dest+width) = *((char*)src+width);
		}
	}

	return ret;// 返回目标的首元素地址

}
int main()
{
	int arr[] = { 12,2,3,4,5,6,7 }; 
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_memmove(arr + 5, arr, 8);
	for(int i=0;i<sz;i++)
	{
	printf("%d ",arr[i]);
	}
	
	return 0;
}