#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//汉诺塔游戏：有三根柱子A,B,C，A柱子上有n个碟子，且由上到下从小到大放置
//需要将A柱子上的碟子都移动到C柱子上
//要求一次只能挪动一个碟子，并且挪动过程中始终保持小的碟子在大的碟子之上
void move(int n,char X, char Y)//move函数用来打印挪动步骤
{
	printf("%d从%c->%c\n", n,X, Y);
}
//将上n-1个碟子看作一个整体，那么想挪动这两个碟子，先把（n-1）碟子通过C柱子挪到B，再把第n个碟子挪到C
//然后再将（n-2）个碟子看成整体，从B柱子通过A柱子挪到C，形成递归
//当剩下最后一个碟子即n=1时，递归结束
void Hanoi(int n, char X, char Y, char Z)//Hanoi函数用来具体操作
{
	if (n == 1) {
		move(1,X,Z);
	}
	else {
		Hanoi(n - 1, X, Z, Y);
		move(n,X,Z);
		Hanoi(n - 1, Y, X, Z);
	}
}
//主函数,a是汉诺塔层数，A,B,C是三根柱子
int main()
{
	int a;
	char A = 'A';
	char B = 'B';
	char C = 'C';
	printf("请输入汉诺塔的层数：");
	scanf("%d", &a);
	Hanoi(a, A, B, C);
	return 0;
}