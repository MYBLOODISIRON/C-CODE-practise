#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);//����dest��src����ָ���Ƿ�ȫ��ΪNULL
	char* ret = dest;
	while (*dest++ = *src++);
	return ret;

}
int main()
{
	char arr1[] = "abcdefg";
	char arr2[20] = { 0 };
	printf("%s",my_strcpy(arr2, arr1));
	return 0;
}