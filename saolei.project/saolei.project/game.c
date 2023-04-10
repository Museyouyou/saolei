#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
void Initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");

	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row+1;//假如 row = 9  %9的范围在0-8之间     row+1 范围就在1-9之间了 
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y]='1';//'1'代表雷
			count--;//一共10个雷 在循环的过程中 布置一个少一个
		}
	}
}
//'1'-'0'=1 字符1减去字符0等于数字1
//'3'-'0'=3     3的 ascii码值是51   0的 assci码值是48 
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	   return  mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';


}



void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//成功排查
	while (win<row*col-EASY_COUNT)//还没有排完雷
	{
		printf("请输入排查雷的坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			//1.踩雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//2.不是雷
			else
			{
				//计算x y坐标周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y]=count + '0';//   count+'0' 转换成字符
				DisplayBoard(show, row, col);
				win++;//排雷成功
				
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)//雷排完了
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}