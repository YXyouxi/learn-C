#pragma once
//头文件的引用
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//变量定义
#define ROW  3
#define COL  3

//函数的声明
//初始化棋盘
void InitBoard(char board [ROW][COL],int row,int col);
//打印棋盘
void display(char board[ROW][COL], int row, int col);
//玩家行动
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑行动
void ComputerMove(char board[ROW][COL], int row, int col);
//判断胜负
//玩家胜利——返回'*'
//电脑胜利——返回'#'
//平局——返回Q
//游戏继续——返回C
char isWin(char board[ROW][COL], int row, int col);
