#pragma once
//ͷ�ļ�������
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//��������
#define ROW  3
#define COL  3

//����������
//��ʼ������
void InitBoard(char board [ROW][COL],int row,int col);
//��ӡ����
void display(char board[ROW][COL], int row, int col);
//����ж�
void PlayerMove(char board[ROW][COL], int row, int col);
//�����ж�
void ComputerMove(char board[ROW][COL], int row, int col);
//�ж�ʤ��
//���ʤ����������'*'
//����ʤ����������'#'
//ƽ�֡�������Q
//��Ϸ������������C
char isWin(char board[ROW][COL], int row, int col);
