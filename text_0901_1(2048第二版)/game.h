#pragma once

#define ROW 4
#define COL 4

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void game_2048();

//打印菜单
void menu();

//判断是否进行游戏
int start_comand();

//刷新整形数组
void refresh_arr_int(int arr[ROW][COL], int n);

//随机生成数字
void creat_number(int arr[ROW][COL], int row, int col);

//游戏开始
void game_start(int number[ROW][COL]);

//打印游戏界面
void print_game_menu(int board[ROW][COL], int row, int col);

//玩家操作
void player_comand(int address[ROW][COL], int row, int col);

//上移
void move_up(int address[ROW][COL], int row, int col);

//左移
void move_left(int board[ROW][COL], int row, int col);

//下移
void move_down(int board[ROW][COL], int row, int col);

//右移
void move_right(int board[ROW][COL], int row, int col);

//判断是否出现2048
int if_appear_2048(int arr[ROW][COL]);

//判断是否可以移动
int if_can_move(int arr[ROW][COL]);