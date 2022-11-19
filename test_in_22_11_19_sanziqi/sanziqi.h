#pragma once
//关于游戏相关函数的声明，符号声明，头文件的包含
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define ROW  3
#define COL  3

void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘

//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void ManBoard(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerBoard(char board[ROW][COL], int row, int col);
//棋盘是否满了
int IsFull(char board[ROW][COL], int row, int col);
//判断谁赢了
//1、玩家赢，*
//2、电脑赢，$
//3、平局，?
//4、继续，>
char IsWin(char board[ROW][COL], int row, int col);
