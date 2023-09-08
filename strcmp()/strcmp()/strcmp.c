#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* str1, const char* str2)// strcmp()中str1大于str2返回一个大于0的整型，等于返回0，小于返回一个小于0的整型

{
	assert(str1 && str2);// 断言str1和str2是否全不为NULL
	while (*str1 == *str2)// str1指向的字符和str2指向的字符不相等或其中一个为‘\0’时跳出循环
	{
		if (*str1 == 0 || *str2 == 0)
			return 0;
		str1++;
		str2++;
	}

	return ((*str1) - (*str2));

}
int main()
{
	char str1[] = "abcdef";
	char str2[] = "abcdeg";
	int flag = my_strcmp(str1, str2);
	if (flag < 0)
		printf("<");
	else if (flag > 0)
		printf(">");
	else 
		printf("=");

	return 0;
}