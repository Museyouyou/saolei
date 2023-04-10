#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define EASY_COUNT 80//放雷的个数
#define ROWS ROW+2//将数组扩大
#define COLS COL+2

void Initboard(char board[ROWS][COLS],int rows, int cols,char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//FindMine传了两个数组, 所以要接收两个
