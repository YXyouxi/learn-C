//猜数字游戏，随机生成1-100，可以重复玩，输入0退出 
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
	//猜数字游戏的实现,1.随机生成一个1-100的数字，2.猜数字
	//rand函数生成随机数（0-32767） 需要 include<stdlib.h>，返回整型
	//时间是在发生变化的 时间-时间戳 
	int ret=rand()%100+1;
	//猜数字
	int guess=0;
	while(1)
	{
		printf("请猜数字");
		scanf("%d",&guess);
		if(guess<ret){
			printf("猜小了\n");
		}else if(guess>ret)
		{
			printf("猜大了\n"); 
		} else {
			printf("恭喜你，猜对了\n");
			break;
		}
	} 
}
int main()
{
	srand((unsigned int )time(NULL));//time函数本身是有参数的，所以传一个空指针过去 
	int input;
	do
	{
		menu();//打印菜单 
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，重新输入：\n");
				break;
		}
	}while(input);
	return 0;
}
