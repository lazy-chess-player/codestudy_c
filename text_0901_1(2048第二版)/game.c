#include <Windows.h>
#include "game.h"

void main()
{
	game_2048();
}

void game_2048()
{
	srand((unsigned int)time(NULL));
	//��ӡ�˵�
	menu();
	//�ж��Ƿ�����
	if (start_comand())
	{
		//������������洢ÿ��λ�õĴ�С
		int number[ROW][COL]={0};

		//ˢ������
		refresh_arr_int(number, 0);

		//�����������
		creat_number(number,ROW,COL);
		creat_number(number,ROW,COL);

		//������Ϸ
		game_start(number);
	}
	else
		printf("�˳�");
}
void menu()
{
	printf("---------------------------------------------------------\n");
	printf("  ������������         ��������������             ��          ������������\n");
	printf("��        ��     ��         ��         �� ��        ��        ��\n");
	printf("         ��     ��         ��        ��  ��        ��        ��\n");
	printf("       ��       ��         ��      ��    ��          ������������\n");
	printf("      ��        ��         ��    ������������������������    ��        ��\n");
	printf("    ��          ��         ��           ��        ��        ��\n");
	printf("  ��            ��         ��           ��        ��        ��\n");
	printf("��������������������       ��������������             ��          ������������\n");
	printf("---------------------------------------------------------\n");
	printf("              ��ʼ:Y/y            �˳�:N/n\n");
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
		printf("�����������������\n");
		start_comand();
	}
}
void refresh_arr_int(int arr[ROW][COL], int n)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = n;
		}
	}
}
void creat_number(int arr[ROW][COL], int row, int col)
{
	while (1)
	{
		int i = rand() % row + 1;
		int j = rand() % col + 1;
		if (arr[i][j] == 0)
		{
			arr[i][j] = 2 * (rand() % 2 + 1);
			break;
		}
	}
}
void game_start(int number[ROW][COL])
{
	//��ӡ��Ϸ����
	print_game_menu(number, ROW, COL);

	//������Ϸ����
	player_comand(number, ROW, COL);

	//�ж���Ϸ�Ƿ����
	int if_win = if_appear_2048(number);
	if (if_win)
	{
		print_game_menu(number,ROW,COL);
		printf("��ϲ��ʤ");
	}
	int if_false = if_can_move(number);
	if (if_false)
		printf("������");
	if (if_win == 0 && if_false == 0)
	{
		//�����������
		creat_number(number, ROW, COL);
		game_start(number);
	}
}
void print_game_menu(int board[ROW][COL], int row, int col)
{
	system("cls");
	printf("\n\n\n\n");
	printf("             --------------------------------------------------\n\n");
	printf("                        �����������Щ��������Щ��������Щ���������\n");
	for (int i = 0; i < row; i++)
	{
		printf("                        ��");
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] != 0)
			{
				if (board[i][j] < 10)
				{
					printf("  %d ��", board[i][j]);
				}
				else if (board[i][j] < 100)
				{
					printf(" %d ��", board[i][j]);
				}
				else if (board[i][j] < 1000)
				{
					printf(" %d��", board[i][j]);
				}
				else if (board[i][j] < 10000)
				{
					printf("%4d��", board[i][j]);
				}
			}
			else printf("    ��");
		}
		if (i < 3)
		{
			printf("\n                        �����������੤�������੤�������੤��������\n");
		}
		else
		{
			printf("\n                        �����������ة��������ة��������ة���������\n");
		}
	}
	printf("\n");
	printf("             --------------------------------------------------\n");
	printf("                            W��  A��  ��D  ��S\n");
}
void player_comand(int address[ROW][COL], int row, int col)
{
	char cmd = _getch();
	switch (cmd)
	{
	case'w':
	case'W':
	case 72:
		move_up(address, row, col);
		break;
	case'a':
	case'A':
	case 75:
		move_left(address, row, col);
		break;
	case's':
	case'S':
	case 80:
		move_down(address, row, col);
		break;
	case'd':
	case'D':
	case 77:
		move_right(address, row, col);
		break;
	default:
		player_comand(address, row, col);
		break;
	}
}
void move_left(int board[ROW][COL])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1, k = 0; j < 4; j++)
		{
			if (board[i][j] > 0)
			{
				if (board[i][k] == board[i][j])
				{
					board[i][k++] <<= 1;
					board[i][j] = 0;
				}
				else if (board[i][k] == 0)
				{
					board[i][k] = board[i][j];
					board[i][j] = 0;
				}
				else
				{
					board[i][++k] = board[i][j];
					if (j != k)
					{
						board[i][j] = 0;
					}
				}
			}
		}
	}
}


void move_right(int board[ROW][COL])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2, k = 3; j >= 0; j--)
		{
			if (board[i][j] > 0)
			{
				if (board[i][k] == board[i][j])
				{
					board[i][k--] <<= 1;
					board[i][j] = 0;
				}
				else if (board[i][k] == 0)
				{
					board[i][k] = board[i][j];
					board[i][j] = 0;
				}
				else
				{
					board[i][--k] = board[i][j];
					if (j != k)
					{
						board[i][j] = 0;
					}
				}
			}
		}
	}
}

void move_up(int board[ROW][COL])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1, k = 0; j < 4; j++)
		{
			if (board[j][i] > 0)
			{
				if (board[k][i] == board[j][i])
				{
					board[k++][i] <<= 1;
					board[j][i] = 0;
				}
				else if (board[k][i] == 0)
				{
					board[k][i] = board[j][i];
					board[j][i] = 0;
				}
				else
				{
					board[++k][i] = board[j][i];
					if (j != k)
					{
						board[j][i] = 0;
					}
				}
			}
		}
	}
}
void move_down(int board[ROW][COL])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2, k = 3; j >= 0; j--)
		{
			if (board[j][i] > 0)
			{
				if (board[k][i] == board[j][i])
				{
					board[k--][i] <<= 1;
					board[j][i] = 0;
				}
				else if (board[k][i] == 0)
				{
					board[k][i] = board[j][i];
					board[j][i] = 0;
				}
				else
				{
					board[--k][i] = board[j][i];
					if (j != k)
					{
						board[j][i] = 0;
					}
				}
			}
		}
	}
}
int if_appear_2048(int arr[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] == 64)
				return 1;
		}
	}
	return 0;
}
int if_can_move(int arr[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] == 0)
				return 0;
			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j - 1])
				return 0;
		}
	}
	return 1;
}