#define _CRT_SECURE_NO_WARNINGS 1
#include "sanziqi.h"
//��Ϸ��غ�����ʵ��

//��ʼ������
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

//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;//�ȴ�ӡ�У���ΪҪ�ڿո����������ַ���Ӧ��board[][]��һ��һ����
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

//�������
void ManBoard(char board[ROW][COL], int row, int col)
{
	printf("����ߣ�\n");
	int x = 0;
	int y = 0;
	//����Ҫ�ж������Ƿ�Ϸ�
	while (1)
	{
		printf("���������꣺");
		scanf("%d %d", &x, &y);
		//��ȡ�˵�����Ҫ����ߣ���Ȼ��if���棬�������������һֱ���ᱻ��Ϊ�Ƿ�
		//Ҫ�ж������Ƿ�ռ��
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������ѱ�ʹ�ã�����������");
			}
		}
		else
		{
			printf("����Ƿ�����������");
		}
	}
}

//��������
void ComputerBoard(char board[ROW][COL], int row, int col)
{
	printf("�����ߣ�\n");
	//���Բ���Ҫ�ж��Ƿ�Ϸ�
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;//�����Ѿ���������������Ҫscanf��ȡֵ
		//Ҫ�ж������Ƿ�ռ��
		if (board[x][y] == ' ')
		{
			board[x][y] = '$';
			break;
		}
	}
}

//�ж������Ƿ�����
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
				return 0;//0��ʾ����û����
			}
		}
	}
	return 1;
}

//�ж�˭Ӯ��
//1�����Ӯ��*
//2������Ӯ��$
//3��ƽ�֣�?
//4��������>
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int x = 0;//�ж��Ƿ���Ӧ�ֳ���
	//���Ӯ
	//��
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
	//��
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
	//�Խ���#���Ͻǵ����½�
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
	//�Խ���#���Ͻǵ����½�
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
	//����Ӯ
	//��
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
	//��
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
	//�Խ���#���Ͻǵ����½�
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
	//�Խ���#���Ͻǵ����½�
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
	//ƽ��
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
