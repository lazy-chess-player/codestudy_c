#include "game.h"

void game_2048()
{
	srand((unsigned int)time(NULL));
	int board[ROW][COL];
	refresh_board(board,ROW,COL);
	menu();
	if (start_comand())
	{
		creat_number(board, ROW, COL);
		creat_number(board, ROW, COL);
		while (1)
		{
			system("cls");
			display_board(board, ROW, COL);
			player_comand(board, ROW, COL);
			creat_number(board, ROW, COL);
			printf("游戏开始");
		}
	}
	else
		printf("游戏结束");

}
void menu()
{
	printf("  ██████         ███████             █          ██████\n");
	printf("█        █     █         █         █ █        █        █\n");
	printf("         █     █         █        █  █        █        █\n");
	printf("       █       █         █      █    █          ██████\n");
	printf("      █        █         █    ████████████    █        █\n");
	printf("    █          █         █           █        █        █\n");
	printf("  █            █         █           █        █        █\n");
	printf("██████████       ███████             █          ██████\n");
	printf("---------------------------------------------------------\n");
	printf("              开始:Y/y            退出:N/n\n");
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
void refresh_board(int board[ROW][COL], int y, int x)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			board[i][j] = 0;
		}
	}
}
void creat_number(int board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % col;
		int y = rand() % row;
		int number = 2 * (rand() % 2 + 1);
		if (board[y][x] == 0)
		{
			board[y][x] = number;
			break;
		}
		else
			continue;
	}
}
void display_board(int board[ROW][COL], int x, int y)
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
				printf(" %d ", board[i][j]);
		}
		printf("\n");
	}
}
void player_comand(int address[ROW][COL],int y,int x)
{
	char cmd = _getch();
	switch (cmd)
	{
	case'w':
	case'W':
	case 72:
		move_up(address,y,x);
		break;
	case'a':
	case'A':
	case 75:
		move_left(address, y, x);
		break;
	case's':
	case'S':
	case 80:
		move_down(address, y, x);
		break;
	case'd':
	case'D':
	case 77:
		move_right(address, y, x);
		break;
	default:
		player_comand(address,y,x);
		break;
	}
}
void move_up(int address[ROW][COL],int row,int col)
{
	for (int y = 0; y < row-1; y++)
	{
		for (int x = 0;x < col; x++)
		{
			if (address[y][x] == 0)
			{
					address[y][x] = address[y+1][x];
					address[y+1][x] = 0;
			}
			else if (address[y][x] == address[y+1][x])
			{
				address[y][x] += address[y + 1][x];
				address[y + 1][x] = 0;
			}
		}
	}
}
void move_down(int address[ROW][COL],int row,int col)
{
	for (int y = row-1; y > 0; y--)
	{
		for (int x = 0;x < col; x++)
		{
			if (address[y][x] == 0)
			{
					address[y][x] = address[y-1][x];
					address[y-1][x] = 0;
			}
			else if (address[y][x] == address[y-1][x])
			{
				address[y][x] += address[y - 1][x];
				address[y - 1][x] = 0;
			}
		}
	}
}
void move_left(int address[ROW][COL],int row,int col)
{
	for (int y = 0; y < row; y++)
	{
		for (int x = 0;x < col-1; x++)
		{
			if (address[y][x] == 0)
			{
					address[y][x] = address[y][x+1];
					address[y][x+1] = 0;
			}
			else if (address[y][x] == address[y][x+1])
			{
				address[y][x] += address[y][x+1];
				address[y][x+1] = 0;
			}
		}
	}
}
void move_right(int address[ROW][COL],int row,int col)
{
	for (int y = 0; y < row; y++)
	{
		for (int x = col-1;x > 0; x--)
		{
			if (address[y][x] == 0)
			{
					address[y][x] = address[y][x-1];
					address[y][x-1] = 0;
			}
			else if (address[y][x] == address[y][x-1])
			{
				address[y][x] += address[y][x-1];
				address[y][x-1] = 0;
			}
		}
	}
}