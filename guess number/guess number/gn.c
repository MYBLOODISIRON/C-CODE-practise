#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void game()
{
	int num = 0;
	srand((unsigned)time(NULL));
	int jet = rand();
	printf("进入游戏，请输入你的数字\n");
	while (1)
	{
		scanf("%d", &num);
		if (num > jet)printf("猜大了\n");
		else if (num < jet) printf("猜小了\n");
		else break;

	}
	printf("恭喜你，猜对了");
}
int main()
{
	int input = 0;
	do
	{

		printf("---------------------------------------------------\n");
		printf("---------------1.play------0.exist-----------------\n");
		printf("---------------------------------------------------\n");
		printf(" 请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0: return 0;
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}


	} while (input);









	return 0;
}