#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
void start();
void end();
void reset();
void refresh();
void add_rand();
void get_null_count();
//����ϵ
int address[4][4] = { 0 };
//ˢ��״̬
int if_reset = 0;
//����״̬
int if_end = 0;
//�����״̬
int if_add_rand = 1;

//��Ϸ
int main()
{
	start();
}
//��Ϸ�������
void start()
{
	char operation;//��Ҳ���
	operation = getch();
	while (1)
	{
		if (if_end)
		{
			printf("��Ϸ����");
			if (operation == 'n' || operation == 'N')
			{
				system("cls");
				return;
			}
			else
			{
				reset();
				continue;
			}
		}
		else
		{
			switch (operation)
			{
			case'w':
			case'W':
			case 72:
				move_up();
				break;
			case'a':
			case'A':
			case 75:
				move_left();
				break;
			case's':
			case'S':
			case 80:
				move_down();
				break;
			case'd':
			case'D':
			case 77:
				move_right();
				break;
			}
		}
		if (if_add_rand == 1)
		{
			add_rand();
			refresh();
		}
	}
}
//���¿�ʼ
void reset()
{
	if_add_rand = 0;
	if_end = 0;
	int n = rand() % 16;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			address[x][y] = (n-- == 0 ? 2 : 0);
		}
	}
	add_rand();
	system("cls");
	refresh();
}
//��������
void add_rand()
{
	srand(time(0));
	int n = rand() % get_null_count();
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (address[x][y] == 0 && n-- == 0)
			{
				address[x][y] = (rand() % 3 ? 2 : 4);
				return;
			}
		}
	}
}
//Ѱ�ҿ�λ
int get_null_count()
{
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			address[i][j] == 0 ? n++ : 1;
		}
	}
	return n;
}
//����
void end()
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (address[x][y] == address[x][y + 1] || address[y][x] == address[y + 1][x])
			{
				if_end = 0;
				return;
			}
		}
	}
	if_end = 1;
}
//����
void move_up()
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (address[x][y] == 0)
			{
				address[x][y] = address[x][y + 1];
				address[x][y + 1] = 0;
			}
			else
			{
				if (address[x][y + 1] == address[x][y])
				{
					address[x][y] = address[x][y] + address[x][y + 1];
					address[x][y + 1] = 0;
				}
			}
		}
	}
	if_add_rand = 1;
}
//����
void move_down()
{
	for (int x = 3; x >= 0; x++)
	{
		for (int y = 3; y >= 0; y--)
		{
			if (address[x][y] == 0)
			{
				address[x][y] = address[x][y - 1];
				address[x][y - 1] = 0;
			}
			else
			{
				if (address[x][y - 1] == address[x][y])
				{
					address[x][y] = address[x][y] + address[x][y - 1];
					address[x][y - 1] = 0;
				}
			}
		}
	}
	if_add_rand = 1;
}
//����
void move_left()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (address[x][y] == 0)
			{
				address[x][y] = address[x + 1][y];
				address[x + 1][y] = 0;
			}
			else
			{
				if (address[x + 1][y] == address[x][y])
				{
					address[x][y] = address[x][y] + address[x + 1][y];
					address[x + 1][y] = 0;
				}
			}
		}
	}
	if_add_rand = 1;
}
//����
void move_right()
{
	for (int y = 3; y >= 0; y--)
	{
		for (int x = 3; x >= 0; x--)
		{
			if (address[x][y] == 0)
			{
				address[x][y] = address[x - 1][y];
				address[x - 1][y] = 0;
			}
			else
			{
				if (address[x - 1][y] == address[x][y])
				{
					address[x][y] = address[x][y] + address[x - 1][y];
					address[x - 1][y] = 0;
				}
			}
		}
	}
	if_add_rand = 1;
}
//ˢ�½���
void refresh()
{
	/* ���������λ�÷�ʽ�������Լ�����˸��system("cls")Ϊ�������������ΪWindowsƽ̨���*/
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("                        �����������Щ��������Щ��������Щ���������\n");
	for (int i = 0; i < 4; i++)
	{
		printf("                        ��");
		for (int j = 0; j < 4; j++)
		{
			if (address[i][j] != 0)
			{
				if (address[i][j] < 10)
				{
					printf("  %d ��", address[i][j]);
				}
				else if (address[i][j] < 100)
				{
					printf(" %d ��", address[i][j]);
				}
				else if (address[i][j] < 1000)
				{
					printf(" %d��", address[i][j]);
				}
				else if (address[i][j] < 10000)
				{
					printf("%4d��", address[i][j]);
				}
				else
				{
					int n = address[i][j];
					for (int k = 1; k < 20; k++)
					{
						n >>= 1;
						if (n == 1)
						{
							printf("2^%02d��", k);
							break;
						}
					}
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
	printf("                            W��  A��  ��D  ��S");

	if (get_null_count() == 0)
	{
		end();
		if (if_end)
		{
			printf("\r                    GAME OVER! TRY THE GAME AGAIN? [Y/N]");
		}
	}
}