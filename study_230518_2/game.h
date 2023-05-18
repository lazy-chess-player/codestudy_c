#pragma once

#define X 3
#define Y 3

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void game();
void menu();
int start_comand();
void refresh_board(char board[Y][X], int x, int y);
void display_board(char board[Y][X], int x, int y);
void player_action(char board[Y][X]);
void computer_action(char board[Y][X]);
char if_end(char board[Y][X]);
int if_full(char board[Y][X]);
