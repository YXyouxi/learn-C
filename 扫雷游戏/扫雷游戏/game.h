#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define easycount 10

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//������
void Setmine(char board[ROWS][COLS], int row, int col);
//�Ų���
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);