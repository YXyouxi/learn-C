#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char input[20]={0};
	system("shutdown -s -t 60");//系统命令 ,需要#include<stdlib.h>头文件 
again:
	printf("您的电脑将会在60秒后关机，输入：我是猪将会取消关机\n"); 
	scanf("%s",input);//因为input是数组，不需要取地址
	if(strcmp(input,"我是猪")==0){    //strcmp，比较两个字符串是否相同，需要#include<string.h>头文件 
		system("shutdown -a");
	}
	else{
		goto again;
	}
	return 0;
}
