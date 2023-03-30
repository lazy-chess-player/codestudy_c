#pragma once

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE_NUMBER 10

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//��Ϸ
void game();

//��ӡ�˵�
void menu();

//��ʼָ��
int start_comand();

//ˢ������
void refresh_board(char board[ROWS][COLS], int x, int y, char set);

//��ӡ����
void display_board(char board[ROWS][COLS],int x,int y);

//���ɵ���
void creat_mine(char mine[ROWS][COLS], int row, int col, int count);

//�Ų����
void search_mine(char board[ROWS][COLS], char show[ROWS][COLS]);

//��õ�����
char get_mine(char mine[ROWS][COLS], int x, int y);