#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)// num是所需要改变的字节的数目，不是需要改变的元素的数目！！
{
	assert(dest && src); // 断言dest和src是否全不为NULL
	char* Dest = (char*)dest;// void*类型的指针不能进行间接访问操作和指针运算
	char* Src = (char*) src;
	
	while (num--)
	{
		*Dest = *Src;
		Dest+=1;
 		Src+=1;

 	}
	return dest; // 返回目标空间的首元素地址
}
int main()
{
	int arr1[20] = { 1,2,3,4,5 };
	int arr2[] = { 6,7,8,9 };
	size_t bytes = sizeof(arr2);

	my_memcpy(arr1, arr2, bytes);

	int len = bytes / sizeof(arr2[1]);
	for (int i = 0; i <len ; i++)
	{
		printf("%d\n", arr1[i]);
	}
	return 0;
}