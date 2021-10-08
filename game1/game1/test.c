#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	//�洢���ݡ�����ά����
	char board [ROW][COL];
	//��ʼ�����̡�����ʼ��Ϊ�ո�
	InitBoard(board, ROW, COL);
	//��ӡ���̡��������Ǵ�ӡ����
	display(board, ROW, COL);
	char ret;
	while (1) {
		//����ж�
		PlayerMove(board, ROW, COL);
		display(board, ROW, COL);
		//�ж���Ϸ״̬
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//�����ж�
		ComputerMove(board, ROW, COL);
		display(board, ROW, COL);
		//�ж���Ϸ״̬
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("��һ�ʤ\n");
	}
	else if (ret == '#') {
		printf("���Ի�ʤ\n");
	}
	else {
		printf("ƽ��\n");
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룺\n");
			break;
		}
	} while (input);
	return 0;
}