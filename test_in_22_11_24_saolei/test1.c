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
	char lei[ROWS][COLS] = { 0 };//����
	char show[ROWS][COLS] = { 0 };//����
	//��ʼ������
	InitBoard(lei, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');

	//PrintBoard(lei, ROWS, COLS);
	//printf("--------------------------\n");
	//��ӡ����
	PrintBoard(show, ROW, COL);

	//������
	Set(lei, ROW, COL);
	//PrintBoard(lei, ROW, COL);

	//����
	Check(lei, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}