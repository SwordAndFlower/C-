#define _CRT_SECURE_NO_WARNINGS 1
#include "sanziqi.h"
//������
//������Ϸ���߼�
void menu()
{
	printf("*********************\n");
	printf("****   1.play   *****\n");
	printf("****   0.exit   *****\n");
	printf("*********************\n");
}
void game()
{
	char board[ROW][COL];//�����洢���ݵĶ�ά����
	InitBoard(board, ROW, COL);//��ʼ������

	PrintBoard(board, ROW, COL);//��ӡ����
	char result = 0;
	while (1)
	{
		//�������
		ManBoard(board, ROW, COL);
		PrintBoard(board, ROW, COL);//չʾ���
		result = IsWin(board, ROW, COL);//�ж�����Ƿ�Ӯ
		if (result != '>')
		{
			break;
		}
		//��������
		ComputerBoard(board, ROW, COL);
		PrintBoard(board, ROW, COL);//չʾ���
		result = IsWin(board, ROW, COL);//�жϵ����Ƿ��ʤ
		if (result != '>')
		{
			break;
		}
	}
	if (result == '*')
	{
		printf("���Ӯ\n");
	}
	if (result == '$')
	{
		printf("����Ӯ\n");
	}
	if (result == '?')
	{
		printf("ƽ��\n");
	}
	PrintBoard(board, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	//���ò˵�����ȡ��Ϸ�������
	//�жϽ�����Ϸ�����˳�
	do
	{
		menu();
		printf("��ѡ�񣺡�>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��ʼ��Ϸ
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}