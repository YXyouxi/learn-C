#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void print(unsigned n)
{
	if (n > 9) {
		print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	unsigned int num = 0;
	scanf("%u", &num);
	//递归-打印num的每一位
	print(num);
	return 0;
}