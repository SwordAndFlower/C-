#pragma once
//������Ϸ��غ���������������������ͷ�ļ��İ���
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define ROW  3
#define COL  3

void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������

//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col);
//�������
void ManBoard(char board[ROW][COL], int row, int col);
//��������
void ComputerBoard(char board[ROW][COL], int row, int col);
//�����Ƿ�����
int IsFull(char board[ROW][COL], int row, int col);
//�ж�˭Ӯ��
//1�����Ӯ��*
//2������Ӯ��$
//3��ƽ�֣�?
//4��������>
char IsWin(char board[ROW][COL], int row, int col);
