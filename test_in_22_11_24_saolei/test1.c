#define _CRT_SECURE_NO_WARNINGS 1
#include "saolei.h"
void menu()
{
	printf("--------------------------\n");
	printf("--------  1.play  --------\n");
	printf("--------  0.exit  --------\n");
	printf("--------------------------\n");
}
void game()
{
	char lei[ROWS][COLS] = { 0 };//放雷
	char show[ROWS][COLS] = { 0 };//排雷
	//初始化棋盘
	InitBoard(lei, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');

	//PrintBoard(lei, ROWS, COLS);
	//printf("--------------------------\n");
	//打印棋盘
	PrintBoard(show, ROW, COL);

	//布置雷
	Set(lei, ROW, COL);
	//PrintBoard(lei, ROW, COL);

	//排雷
	Check(lei, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}