#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
const char* my_strstr(const char* str1, const char* str2)// str2����str1���Ӵ��򷵻�str2�״���str1�г���λ�õĵ�ַ���������򷵻�NULL
{
	
	assert(str1 && str2);//����str1��str2�Ƿ�ȫ��ΪNULL
	
	const char* s2 = str2;
	const char* p = str1;
	const char* s1 = p;
	while (*p)
	{
		s1 = p;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return p;// ����str2�״���str1�г���λ�õĵ�ַ
		p++;
	}
	return NULL;

}
int main()
{
	char str1 [] = "abbbbcdefg";
	char str2[] = "cdefg";
	printf("%s",my_strstr(str1, str2));
	return 0;
}