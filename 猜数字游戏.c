//��������Ϸ���������1-100�������ظ��棬����0�˳� 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("***********************\n");
	printf("*********1.play********\n");
	printf("*********0.exit********\n");
	printf("***********************\n");
}
void game()
{
	//��������Ϸ��ʵ��,1.�������һ��1-100�����֣�2.������
	//rand���������������0-32767�� ��Ҫ include<stdlib.h>����������
	//ʱ�����ڷ����仯�� ʱ��-ʱ��� 
	int ret=rand()%100+1;
	//������
	int guess=0;
	while(1)
	{
		printf("�������");
		scanf("%d",&guess);
		if(guess<ret){
			printf("��С��\n");
		}else if(guess>ret)
		{
			printf("�´���\n"); 
		} else {
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	} 
}
int main()
{
	srand((unsigned int )time(NULL));//time�����������в����ģ����Դ�һ����ָ���ȥ 
	int input;
	do
	{
		menu();//��ӡ�˵� 
		printf("��ѡ��");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ������������룺\n");
				break;
		}
	}while(input);
	return 0;
}
