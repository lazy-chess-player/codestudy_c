#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//��Ϸ����
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
				printf("��ϲ��ʤ\n");
				break;
			}
			computer_action(board);
			system("cls");
			display_board(board, X, Y);
			ret = if_end(board);
			if (ret == '#')
			{
				printf("������\n");
				break;
			}
			if (ret == 'F')
			{
				printf("ƽ��\n");
				break;
			}
			if (ret == 'F')
			{
				printf("ƽ��\n");
				break;
			}
			if (ret == 'C')
				continue;
		}
		game();
	}
}
//��ӡ�˵�
void menu()
{
	printf("        ������        \n");
	printf("��ʼ:Y/y      ����:N/n\n");
}
//��ʼָ��
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
		printf("�����������������\n");
		start_comand();
	}
}
//ˢ������
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
//��ӡ����
void display_board(char board[Y][X], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < y + 1; i++)
	{
		for (j = 0; j < x + 1; j++)
		{
			if (i == 0 && j == 0)
				printf("��");
			if ((i > 0 && i < y) && j == 0)
				printf("��");
			if (i == y && j == 0)
				printf("��");

			if (i == 0 && (j > 0 && j < x))
				printf("��");
			if ((i > 0 && i < y) && (j > 0 && j < x))
				printf("��");
			if (i == y && (j > 0 && j < x))
				printf("��");

			if (i == 0 && j == x)
				printf("��");
			if ((i > 0 && i < y) && j == x)
				printf("��");
			if (i == y && j == x)
				printf("��");

			if (j < x && i < y + 1)
				printf("������");
		}
		printf("\n");
		for (j = 0; j < x + 2; j++)
		{
			if (j < x + 1 && i < y)
				printf("��");
			if (j < x && i < y)
				printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}
//����ж�
void player_action(char board[Y][X])
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("\n����������=>");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= X && y > 0 && y <= Y && board[y - 1][x - 1] == ' ')
		{
			board[y - 1][x - 1] = '*';
			break;
		}
		else
		{
			printf("������Ч");
		}
	}
}
//�����ж�
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
//�ж���Ϸ״̬
char if_end(char board[Y][X])
{
	int i = 0;
	//�бȽ�
	for (i = 0; i < X; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//�бȽ�
	for (i = 0; i < Y; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	//�Խ��߱Ƚ�
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
//�ж��Ƿ��п�λ
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