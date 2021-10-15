#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0, j = 0;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	printf("----------ɨ��----------\n");
	//��ӡ�к�
	for (i = 0; i <= col; i++) {
		printf("%d ", i);
	}
	printf("\n");
	//��ӡ�к�
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------ɨ��----------\n");
}

void Setmine(char board[ROWS][COLS], int row, int col)
{
	//����ʮ����
	int count = easycount;

	while (count > 0) {
		//�����������
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		//����Ƿ��Ѿ���������
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

static int getmine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + 
		   mine[x - 1][y] + 
		   mine[x - 1][y + 1] + 
		   mine[x][y - 1] + 
		   mine[x][y + 1] + 
		   mine[x + 1][y - 1] + 
		   mine[x + 1][y] + 
		   mine[x + 1][y + 1] - 8 * '0';
}

void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//�����Ų������
	//��������Ƿ�����
		//(1)���ס������ź���ը����
		//(2)�����ס��������Χ�м����ף���Ϸ�������洢�Ų��׵���Ϣ��show����
	int x = 0, y = 0;
	int win = 0;
	while (win<row*col-  easycount ) {
		printf("������Ҫ�Ų������");
		scanf("%d%d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else {
				//ͳ����Χ�׵���Ϣ
				int count = getmine(mine, x, y);
				show[x][y] = count + '0';//Ϊ�˰�count������ת��Ϊ�ַ�
				DisplayBoard(show, ROW, COL);
			}
		}
		else {
			printf("����Ƿ�������������");
		}
	}
	if (win == row * col - easycount) {
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(show, row, col);
	}
}