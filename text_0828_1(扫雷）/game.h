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

//游戏
void game();

//打印菜单
void menu();

//开始指令
int start_comand();

//刷新数组
void refresh_board(char board[ROWS][COLS], int x, int y, char set);

//打印数组
void display_board(char board[ROWS][COLS],int x,int y);

//生成地雷
void creat_mine(char mine[ROWS][COLS], int row, int col, int count);

//排查地雷
void search_mine(char board[ROWS][COLS], char show[ROWS][COLS]);

//获得地雷数
char get_mine(char mine[ROWS][COLS], int x, int y);