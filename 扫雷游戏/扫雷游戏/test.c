#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("************************\n");
	printf("******   1.play   ******\n");
	printf("******   0.exit   ******\n");
	printf("************************\n");
}
void game()
{
	char mine[ROWS][COLS];//存放布置的雷的信息
	char show[ROWS][COLS];//存放排查的雷的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS,'0');//全为'0'
	InitBoard(show, ROWS, COLS,'*');//全为'*'
	//打印棋盘
	// mine棋盘打印只是为了检查有无错误，真正运行时注释掉
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	Setmine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//排查雷
	Findmine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned)time(NULL));
	int input;
	do {
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择:\n");
			break;
		}
	} while (input);
	return 0;
}