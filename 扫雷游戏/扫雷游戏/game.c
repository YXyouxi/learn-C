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
	printf("----------扫雷----------\n");
	//打印列号
	for (i = 0; i <= col; i++) {
		printf("%d ", i);
	}
	printf("\n");
	//打印行号
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------扫雷----------\n");
}

void Setmine(char board[ROWS][COLS], int row, int col)
{
	//布置十个雷
	int count = easycount;

	while (count > 0) {
		//生成随机坐标
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		//检测是否已经布置了雷
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
	//输入排查的坐标
	//检查坐标是否是雷
		//(1)是雷——很遗憾，炸死了
		//(2)不是雷——检测周围有几个雷，游戏继续，存储排查雷的信息到show数组
	int x = 0, y = 0;
	int win = 0;
	while (win<row*col-  easycount ) {
		printf("请输入要排查的坐标");
		scanf("%d%d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else {
				//统计周围雷的信息
				int count = getmine(mine, x, y);
				show[x][y] = count + '0';//为了把count从数字转化为字符
				DisplayBoard(show, ROW, COL);
			}
		}
		else {
			printf("坐标非法，请重新输入");
		}
	}
	if (win == row * col - easycount) {
		printf("恭喜你，排雷成功\n");
		DisplayBoard(show, row, col);
	}
}