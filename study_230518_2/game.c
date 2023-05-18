#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//游戏运行
void game()
{
	char board[Y][X];
	char ret = ' ';
	srand((unsigned int)time(NULL));
	refresh_board(board, X, Y);
	menu();
	int if_game_start = start_comand();
	if (if_game_start == 1)
	{
		display_board(board, X, Y);
		while (1)
		{
			player_action(board);
			system("cls");
			display_board(board, X, Y);
			ret = if_end(board);
			if (ret == '*')
			{
				printf("恭喜获胜\n");
				break;
			}
			computer_action(board);
			system("cls");
			display_board(board, X, Y);
			ret = if_end(board);
			if (ret == '#')
			{
				printf("你输了\n");
				break;
			}
			if (ret == 'F')
			{
				printf("平局\n");
				break;
			}
			if (ret == 'F')
			{
				printf("平局\n");
				break;
			}
			if (ret == 'C')
				continue;
		}
		game();
	}
}
//打印菜单
void menu()
{
	printf("        井字棋        \n");
	printf("开始:Y/y      结束:N/n\n");
}
//开始指令
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
//刷新棋盘
void refresh_board(char board[Y][X], int x, int y)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < y; j++)
	{
		for (i = 0; i < x; i++)
		{
			board[j][i] = ' ';
		}
	}
}
//打印棋盘
void display_board(char board[Y][X], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < y + 1; i++)
	{
		for (j = 0; j < x + 1; j++)
		{
			if (i == 0 && j == 0)
				printf("┌");
			if ((i > 0 && i < y) && j == 0)
				printf("├");
			if (i == y && j == 0)
				printf("└");

			if (i == 0 && (j > 0 && j < x))
				printf("┬");
			if ((i > 0 && i < y) && (j > 0 && j < x))
				printf("┼");
			if (i == y && (j > 0 && j < x))
				printf("┴");

			if (i == 0 && j == x)
				printf("┐");
			if ((i > 0 && i < y) && j == x)
				printf("┤");
			if (i == y && j == x)
				printf("┘");

			if (j < x && i < y + 1)
				printf("───");
		}
		printf("\n");
		for (j = 0; j < x + 2; j++)
		{
			if (j < x + 1 && i < y)
				printf("│");
			if (j < x && i < y)
				printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}
//玩家行动
void player_action(char board[Y][X])
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("\n请输入坐标=>");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= X && y > 0 && y <= Y && board[y - 1][x - 1] == ' ')
		{
			board[y - 1][x - 1] = '*';
			break;
		}
		else
		{
			printf("坐标无效");
		}
	}
}
//电脑行动
void computer_action(char board[Y][X])
{
	while (1)
	{
		int x = rand() % X;
		int y = rand() % Y;
		if (x > 0 && x <= X && y > 0 && y <= Y && board[y][x] == ' ')
		{
			board[y][x] = '#';
			break;
		}
		else
			continue;
	}

}
//判断游戏状态
char if_end(char board[Y][X])
{
	int i = 0;
	//列比较
	for (i = 0; i < X; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//行比较
	for (i = 0; i < Y; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	//对角线比较
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')
		return  board[1][1];
	if (board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[1][1] != ' ')
		return  board[1][1];

	int input = if_full(board);
	if (input == 1)
		return 'F';
	else
		return 'C';
}
//判断是否有空位
int if_full(char board[Y][X])
{
	int i = 0;
	int j = 0;
	for (j = 0; j < Y; j++)
	{
		for (i = 0; i < X; i++)
		{
			if (board[j][i] == ' ')
				return 0;
		}
	}
	return 1;
}