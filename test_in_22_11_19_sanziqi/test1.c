#define _CRT_SECURE_NO_WARNINGS 1
#include "sanziqi.h"
//三子棋
//测试游戏的逻辑
void menu()
{
	printf("*********************\n");
	printf("****   1.play   *****\n");
	printf("****   0.exit   *****\n");
	printf("*********************\n");
}
void game()
{
	char board[ROW][COL];//用来存储数据的二维数组
	InitBoard(board, ROW, COL);//初始化棋盘

	PrintBoard(board, ROW, COL);//打印棋盘
	char result = 0;
	while (1)
	{
		//玩家下棋
		ManBoard(board, ROW, COL);
		PrintBoard(board, ROW, COL);//展示结果
		result = IsWin(board, ROW, COL);//判断玩家是否赢
		if (result != '>')
		{
			break;
		}
		//电脑下棋
		ComputerBoard(board, ROW, COL);
		PrintBoard(board, ROW, COL);//展示结果
		result = IsWin(board, ROW, COL);//判断电脑是否获胜
		if (result != '>')
		{
			break;
		}
	}
	if (result == '*')
	{
		printf("玩家赢\n");
	}
	if (result == '$')
	{
		printf("电脑赢\n");
	}
	if (result == '?')
	{
		printf("平局\n");
	}
	PrintBoard(board, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	//调用菜单，获取游戏进入界面
	//判断进入游戏还是退出
	do
	{
		menu();
		printf("请选择：—>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//开始游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);

	return 0;
}