#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void menu()
{
	printf("******************************\n");
	printf("******1.ADD    2.del   *******\n");
	printf("******3.search 4.modify*******\n");
	printf("******5.sort   6.print *******\n");
	printf("******     0.exit      *******\n");
	printf("******************************\n");
}

enum option 
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};

int main()
{
	int input = 0;
	//����ͨѶ¼
	Contact(con);
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do {
		menu();
		printf("��ѡ��");
		(void)scanf("%d", &input);
		switch (input){
		case ADD:
			//�����˵���Ϣ
			AddContact(&con);
			break;
		case DEL:
			//ɾ���˵���Ϣ
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			break;
		case PRINT:
			//��ʾͨѶ¼������Ϣ
			PrintContact(&con);
			break;
		case EXIT:
			//����ͨѶ¼
			Destory(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
