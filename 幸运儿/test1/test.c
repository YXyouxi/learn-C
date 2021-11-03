#define _CRT_SECURE_NO_WARNINGS 1
//4、寻找幸运儿。n个人围成一圈，并依次编号1~n，从编号为1的人开始，按顺时针方向每隔一人选一个出圈，
//剩下的人重新围成一圈，接上一轮继续每隔一人选一个出圈，如此循环直到剩下两人，这剩下的两人就是幸运儿。
//编写程序，要求输出出圈顺序以及两名幸运儿的初始位置。
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[100] = { 0 };//用于查找剩下的两个人，0代表出圈，1代表还在
	int i = 0;
	int num = n;
	int j = 2;
	for (i = 1; i <= n; i++) {
		arr[i] = 1;//n个人全部都在
	}
	i = 1;
	while (num>2) {
		while (i <= n) {
			printf("出圈的人为%d号\n", i);
			arr[i] = 0;//出圈的人置为0
			i += j;//第一轮1/3/5....第二轮2、6/10....，可以发现出圈规律是第n轮：每隔1+2^(n-1)人出圈
			num--;//剩余人数减1
			if (num <= 2) {
				break;
			}
		}
		i = j;//回到该出圈的人的位置
		j = j * 2;
	}
	for (i = 1; i < n; i++) {
		if (arr[i] != 0) {
			printf("幸运儿是%d\n", i );
		}
	}
	return 0;
}