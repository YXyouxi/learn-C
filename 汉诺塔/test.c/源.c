#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ŵ����Ϸ������������A,B,C��A��������n�����ӣ������ϵ��´�С�������
//��Ҫ��A�����ϵĵ��Ӷ��ƶ���C������
//Ҫ��һ��ֻ��Ų��һ�����ӣ�����Ų��������ʼ�ձ���С�ĵ����ڴ�ĵ���֮��
void move(int n,char X, char Y)//move����������ӡŲ������
{
	printf("%d��%c->%c\n", n,X, Y);
}
//����n-1�����ӿ���һ�����壬��ô��Ų�����������ӣ��Ȱѣ�n-1������ͨ��C����Ų��B���ٰѵ�n������Ų��C
//Ȼ���ٽ���n-2�������ӿ������壬��B����ͨ��A����Ų��C���γɵݹ�
//��ʣ�����һ�����Ӽ�n=1ʱ���ݹ����
void Hanoi(int n, char X, char Y, char Z)//Hanoi���������������
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
//������,a�Ǻ�ŵ��������A,B,C����������
int main()
{
	int a;
	char A = 'A';
	char B = 'B';
	char C = 'C';
	printf("�����뺺ŵ���Ĳ�����");
	scanf("%d", &a);
	Hanoi(a, A, B, C);
	return 0;
}