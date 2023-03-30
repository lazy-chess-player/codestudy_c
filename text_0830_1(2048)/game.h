#pragma once

#define ROW 4
#define COL 4

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//��ʼ����
void menu();

//��ʼָ��
int start_comand();

//ˢ������
void refresh_board(int board[ROW][COL], int y, int x);

//���ɳ�ʼ��
void creat_number(int board[ROW][COL], int row, int col);

//��ӡ����
void display_board(int board[ROW][COL], int x, int y);

//��Ҳ���
void player_comand(int address[ROW][COL], int y, int x);

//����
void move_up(int address[ROW][COL], int row, int col);

//����
void move_down(int address[ROW][COL], int row, int col);

//����
void move_left(int address[ROW][COL], int row, int col);

//����
void move_right(int address[ROW][COL], int row, int col);