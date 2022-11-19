#define _CRT_SECURE_NO_WARNINGS 1
#include "sanziqi.h"
//游戏相关函数的实现

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;//先打印行，因为要在空格里面输入字符，应用board[][]，一行一行来
	for (i = 0; i < row; i++)
	{
		
		for (j = 0; j < col; j++)
		{
			printf(" %c", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("--");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}		
	}
}

//玩家下棋
void ManBoard(char board[ROW][COL], int row, int col)
{
	printf("玩家走：\n");
	int x = 0;
	int y = 0;
	//首先要判断坐标是否合法
	while (1)
	{
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);
		//获取人的坐标要在外边，不然在if里面，坐标是随机数，一直都会被判为非法
		//要判断坐标是否被占用
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被使用，请重新输入");
			}
		}
		else
		{
			printf("坐标非法，重新输入");
		}
	}
}

//电脑下棋
void ComputerBoard(char board[ROW][COL], int row, int col)
{
	printf("电脑走：\n");
	//电脑不需要判断是否合法
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;//电脑已经获得随机数，不需要scanf获取值
		//要判断坐标是否被占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '$';
			break;
		}
	}
}

//判断棋盘是否满了
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//0表示棋盘没有满
			}
		}
	}
	return 1;
}

//判断谁赢了
//1、玩家赢，*
//2、电脑赢，$
//3、平局，?
//4、继续，>
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int x = 0;//判断是否有应局出现
	//玩家赢
	//行
	for (i = 0; i < row; i++)
	{
		int count = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '*')
			{
				count++;
			}
		}
		if (count == row)
		{
			return board[i][0];
			x = 1;
		}
	}
	//列
	for (i = 0; i < row; i++)
	{
		int count = 0;
		for (j = 0; j < col; j++)
		{
			if (board[j][i] == '*')
			{
				count++;
			}
		}
		if (count == row)
		{
			return board[0][i];
			x = 1;
		}
	}
	//对角线#左上角到右下角
	int countm1 = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == '*')
		{
			countm1++;
		}
		if (countm1 == row)
		{
			return board[0][0];
			x = 1;
		}
	}
	//对角线#右上角到左下角
	int countm2 = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][col-1-i] == '*')
		{
			countm2++;
		}
		if (countm2 == row)
		{
			return board[0][col-1];
			x = 1;
		}
	}
	//电脑赢
	//行
	for (i = 0; i < row; i++)
	{
		int count = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '$')
			{
				count++;
			}
		}
		if (count == row)
		{
			return board[i][0];
			x = 1;
		}
	}
	//列
	for (i = 0; i < row; i++)
	{
		int count = 0;
		for (j = 0; j < col; j++)
		{
			if (board[j][i] == '$')
			{
				count++;
			}
		}
		if (count == row)
		{
			return board[0][i];
			x = 1;
		}
	}
	//对角线#左上角到右下角
	int countc1 = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == '$')
		{
			countc1++;
		}
		if (countc1 == row)
		{
			return board[0][0];
			x = 1;
		}
	}
	//对角线#右上角到左下角
	int countc2 = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][col - 1 - i] == '$')
		{
			countc2++;
		}
		if (countc2 == row)
		{
			return board[0][col - 1];
			x = 1;
		}
	}
	//平局
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		if (x != 1)
		{
			return '?';
		}
	}
	else
	{
		return '>';
	}
}
