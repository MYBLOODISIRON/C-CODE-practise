#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* str1, const char* str2)// strcmp()��str1����str2����һ������0�����ͣ����ڷ���0��С�ڷ���һ��С��0������

{
	assert(str1 && str2);// ����str1��str2�Ƿ�ȫ��ΪNULL
	while (*str1 == *str2)// str1ָ����ַ���str2ָ����ַ�����Ȼ�����һ��Ϊ��\0��ʱ����ѭ��
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