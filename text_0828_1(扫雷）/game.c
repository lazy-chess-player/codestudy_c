#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	menu();
	refresh_board(mine, ROWS, COLS,'0');
	refresh_board(show, ROWS, COLS,'*');
	creat_mine(mine, ROW, COL, MINE_NUMBER);
	int input = start_comand();
	if (input == 1)
	{
		display_board(show, ROW, COL);
		search_mine(mine,show);
	}
	else
	{
		printf("结束\n");
	}
}
void menu()
{
	printf("    █\n");
	printf("    █     ██████  \n");
	printf(" ██████        █  \n");
	printf("    █          █  \n");
	printf("    ██     █████  \n");
	printf("   ██          █  \n");
	printf(" █  █          █  \n");
	printf("   ██     ██████  \n");
	printf("    █\n");
	printf("开始:Y/y  结束:N/n\n");
}
int start_comand()
{
	char cmd = _getch();
	switch (cmd)
	{
	case 'Y':
	case 'y':
		system("cls");
		return 1;
		break;
	case 'N':
	case 'n':
		system("cls");
		return 0;
		break;
	default:
		printf("输入错误，请重新输入\n");
		start_comand();
	}
}
void refresh_board(char board[ROWS][COLS], int y, int x, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			board[i][j] = set;
		}
	}
}
void display_board(char board[ROWS][COLS], int y, int x)
{
	int i = 1;
	int j = 1;
	int k = 0;
	printf("--------扫雷--------\n");
	for (k = 0; k<= COL; k++)
	{
		printf(" %d",k);
	}
	printf("\n");
	for (i = 1; i <= y; i++)
	{
		printf(" %d", i);
		for (j = 1; j <= x; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
}
void creat_mine(char mine[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % col + 1;
		int y = rand() % row + 1;
		if (mine[y][x] == '0')
		{
			mine[y][x] = '1';
			count--;
		}
	}
}
void search_mine(char mine[ROWS][COLS],char show[ROWS][COLS])
{
	int ifwin = ROW * COL - MINE_NUMBER;
	while (ifwin)
	{
		int x = 0;
		int y = 0;
		printf("请输入坐标=>");
		scanf("%d %d", &x, &y);
		if (mine[y][x] == '1')
		{
			system("cls");
			display_board(mine, ROW, COL);
			printf("你被炸死了");
			break;
		}
		else
		{
			system("cls");
			show[y][x] = get_mine(mine,x,y)+'0';
			display_board(show, ROW, COL);
			ifwin--;
		}
	}
	display_board(mine, ROW, COL);
	printf("游戏结束");
}
char get_mine(char mine[ROWS][COLS], int x, int y)
{
	return mine[y-1][x-1] + 
		mine[y-1][x] + 
		mine[y-1][x+1] + 
		mine[y][x-1] + 
		mine[y][x+1] + 
		mine[y+1][x-1] + 
		mine[y+1][x] + 
		mine[y+1][x+1] - 
		8 * '0';
}