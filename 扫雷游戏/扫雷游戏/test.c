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
	char mine[ROWS][COLS];//��Ų��õ��׵���Ϣ
	char show[ROWS][COLS];//����Ų���׵���Ϣ
	//��ʼ������
	InitBoard(mine, ROWS, COLS,'0');//ȫΪ'0'
	InitBoard(show, ROWS, COLS,'*');//ȫΪ'*'
	//��ӡ����
	// mine���̴�ӡֻ��Ϊ�˼�����޴�����������ʱע�͵�
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//������
	Setmine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//�Ų���
	Findmine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned)time(NULL));
	int input;
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
			printf("ѡ�����������ѡ��:\n");
			break;
		}
	} while (input);
	return 0;
}