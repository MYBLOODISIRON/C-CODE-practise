#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);// 断言dest和src是否全不为NULL
	char* ret = dest;
	while (* dest != '\0')// 当dest指向的元素为'\0'时跳出循环
	{
		                 
		dest++;

	}
	while (*dest++ = *src++);


	return ret;// strcat()返回目标的起始位置
}


int main()
{
	char dest[20] = "abcd";
	char src[] = "efg";

	printf("%s\n",my_strcat(dest, src));
	return 0;
}