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
	//创建通讯录
	Contact(con);
	//初始化通讯录
	InitContact(&con);

	do {
		menu();
		printf("请选择：");
		(void)scanf("%d", &input);
		switch (input){
		case ADD:
			//增加人的信息
			AddContact(&con);
			break;
		case DEL:
			//删除人的信息
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
			//显示通讯录已有信息
			PrintContact(&con);
			break;
		case EXIT:
			//销毁通讯录
			Destory(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
