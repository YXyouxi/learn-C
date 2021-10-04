#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d ", ret);
	return 0;
}
//用迭代的方式求第n个斐波那契数，虽然写起来复杂，但是效率更高了