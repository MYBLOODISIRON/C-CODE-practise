#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void game()
{
	int num = 0;
	srand((unsigned)time(NULL));
	int jet = rand();
	printf("������Ϸ���������������\n");
	while (1)
	{
		scanf("%d", &num);
		if (num > jet)printf("�´���\n");
		else if (num < jet) printf("��С��\n");
		else break;

	}
	printf("��ϲ�㣬�¶���");
}
int main()
{
	int input = 0;
	do
	{

		printf("---------------------------------------------------\n");
		printf("---------------1.play------0.exist-----------------\n");
		printf("---------------------------------------------------\n");
		printf(" ��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0: return 0;
			break;
		default:
			printf("�����������������\n");
			break;
		}


	} while (input);









	return 0;
}