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
	//��ӡ�к�
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
		int x = rand() % row+1;//���� row = 9  %9�ķ�Χ��0-8֮��     row+1 ��Χ����1-9֮���� 
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y]='1';//'1'������
			count--;//һ��10���� ��ѭ���Ĺ����� ����һ����һ��
		}
	}
}
//'1'-'0'=1 �ַ�1��ȥ�ַ�0��������1
//'3'-'0'=3     3�� ascii��ֵ��51   0�� assci��ֵ��48 
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
	int win = 0;//�ɹ��Ų�
	while (win<row*col-EASY_COUNT)//��û��������
	{
		printf("�������Ų��׵�����\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			//1.����
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//2.������
			else
			{
				//����x y������Χ�м�����
				int count = get_mine_count(mine, x, y);
				show[x][y]=count + '0';//   count+'0' ת�����ַ�
				DisplayBoard(show, row, col);
				win++;//���׳ɹ�
				
			}
		}
		else
		{
			printf("��������Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)//��������
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, row, col);
	}
}