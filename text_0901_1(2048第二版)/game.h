#pragma once

#define ROW 4
#define COL 4

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void game_2048();

//��ӡ�˵�
void menu();

//�ж��Ƿ������Ϸ
int start_comand();

//ˢ����������
void refresh_arr_int(int arr[ROW][COL], int n);

//�����������
void creat_number(int arr[ROW][COL], int row, int col);

//��Ϸ��ʼ
void game_start(int number[ROW][COL]);

//��ӡ��Ϸ����
void print_game_menu(int board[ROW][COL], int row, int col);

//��Ҳ���
void player_comand(int address[ROW][COL], int row, int col);

//����
void move_up(int address[ROW][COL], int row, int col);

//����
void move_left(int board[ROW][COL], int row, int col);

//����
void move_down(int board[ROW][COL], int row, int col);

//����
void move_right(int board[ROW][COL], int row, int col);

//�ж��Ƿ����2048
int if_appear_2048(int arr[ROW][COL]);

//�ж��Ƿ�����ƶ�
int if_can_move(int arr[ROW][COL]);