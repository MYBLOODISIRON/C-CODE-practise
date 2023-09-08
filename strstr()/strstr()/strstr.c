#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
const char* my_strstr(const char* str1, const char* str2)// str2若是str1的子串则返回str2首次在str1中出现位置的地址，若不是则返回NULL
{
	
	assert(str1 && str2);//断言str1和str2是否全不为NULL
	
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
			return p;// 返回str2首次在str1中出现位置的地址
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