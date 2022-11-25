#define _CRT_SECURE_NO_WARNINGS 1
#include "saolei.h"

void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row , int col)
{
	int i = 0;
	int j = 0;
	printf("-------  扫雷游戏  -------\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------  扫雷游戏  -------\n");
}

void Set(char board[ROWS][COLS], int row, int col)
{
	int count = BOOMS;
	while (count)
	{
		int setx = rand() % row + 1;
		int sety = rand() % col + 1;			
		if (board[setx][sety] == '0')
		{
			board[setx][sety] = '1';
			count--;
		}	
	}
}

static int boom_number(char lei[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			count = count + lei[i][j] - '0';
		}
	}
	return count;
}
void Check(char lei[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int getx = 0;
	int gety = 0;
	int booms = 0;
	int win = 0;
	while (win<row*col-BOOMS)
	{
		printf("请输入排查坐标：");
		scanf("%d %d", &getx, &gety);
		if (getx >= 1 && getx <= 9 && gety >= 1 && gety)
		{
			if (lei[getx][gety] == '0')
			{
				booms = boom_number(lei, getx, gety);
				show[getx][gety] = booms + '0';
				PrintBoard(show, ROW, COL);
				win++;
			}
			else
			{
				printf("很不幸，您排雷失败！\n");
				PrintBoard(lei, ROW, COL);
				break;
			}
		}
		else
		{
			printf("坐标不符合，请重新输入!\n");
		}
	}
	if (win == row * col - BOOMS)
	{
		printf("恭喜你！排雷成功！\n");
		PrintBoard(lei, ROW, COL);
	}
}