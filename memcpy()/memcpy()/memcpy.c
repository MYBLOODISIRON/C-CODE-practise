#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)// num������Ҫ�ı���ֽڵ���Ŀ��������Ҫ�ı��Ԫ�ص���Ŀ����
{
	assert(dest && src); // ����dest��src�Ƿ�ȫ��ΪNULL
	char* Dest = (char*)dest;// void*���͵�ָ�벻�ܽ��м�ӷ��ʲ�����ָ������
	char* Src = (char*) src;
	
	while (num--)
	{
		*Dest = *Src;
		Dest+=1;
 		Src+=1;

 	}
	return dest; // ����Ŀ��ռ����Ԫ�ص�ַ
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