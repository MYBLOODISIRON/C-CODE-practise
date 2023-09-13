#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void* my_memmove(void* dest,const void *src,int width)// memmove�������ڶ�����Ŀ���
// width ��ʾ��Ҫ�������ֽ���
{
	assert(dest && src);// ����dest��src�Ƿ�ȫ��ΪNULL
	void* ret = dest;
	if (dest > src)// dest����srcʱ����ǰ���󿽱�����������ݵĸ���
	{
		while (width--)
		{
			*(char*) dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else if (dest < src)// src����destʱ���Ӻ���ǰ�����������ɸ�������
	{
		while (width--)
		{
			*((char*)dest+width) = *((char*)src+width);
		}
	}

	return ret;// ����Ŀ�����Ԫ�ص�ַ

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