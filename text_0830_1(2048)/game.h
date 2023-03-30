#pragma once

#define ROW 4
#define COL 4

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//开始界面
void menu();

//开始指令
int start_comand();

//刷新数组
void refresh_board(int board[ROW][COL], int y, int x);

//生成初始数
void creat_number(int board[ROW][COL], int row, int col);

//打印界面
void display_board(int board[ROW][COL], int x, int y);

//玩家操作
void player_comand(int address[ROW][COL], int y, int x);

//上移
void move_up(int address[ROW][COL], int row, int col);

//下移
void move_down(int address[ROW][COL], int row, int col);

//左移
void move_left(int address[ROW][COL], int row, int col);

//右移
void move_right(int address[ROW][COL], int row, int col);