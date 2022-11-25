#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define BOOMS 10

void InitBoard(char board[ROWS][COLS], int row, int col, char set);

void PrintBoard(char board[ROWS][COLS], int row, int col);

void Set(char board[ROWS][COLS], int row, int col);

void Check(char lei[ROWS][COLS], char show[ROWS][COLS], int row, int col);
