#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	//存储数据——二维数组
	char board [ROW][COL];
	//初始化棋盘——初始化为空格
	InitBoard(board, ROW, COL);
	//打印棋盘——本质是打印数组
	display(board, ROW, COL);
	char ret;
	while (1) {
		//玩家行动
		PlayerMove(board, ROW, COL);
		display(board, ROW, COL);
		//判断游戏状态
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//电脑行动
		ComputerMove(board, ROW, COL);
		display(board, ROW, COL);
		//判断游戏状态
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("玩家获胜\n");
	}
	else if (ret == '#') {
		printf("电脑获胜\n");
	}
	else {
		printf("平局\n");
	}
	display(board, ROW, COL);
}

void menu()
{
	printf("***************************\n");
	printf("********   1.play   *******\n");
	printf("********   0.exit   *******\n");
	printf("***************************\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
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
			printf("输入错误，请重新输入：\n");
			break;
		}
	} while (input);
	return 0;
}