#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);// ����dest��src�Ƿ�ȫ��ΪNULL
	char* ret = dest;
	while (* dest != '\0')// ��destָ���Ԫ��Ϊ'\0'ʱ����ѭ��
	{
		                 
		dest++;

	}
	while (*dest++ = *src++);


	return ret;// strcat()����Ŀ�����ʼλ��
}


int main()
{
	char dest[20] = "abcd";
	char src[] = "efg";

	printf("%s\n",my_strcat(dest, src));
	return 0;
}