#define _CRT_SECURE_NO_WARNINGS 1
//挑选2,3,6为快乐数字，一个整数在十进制表示中只包含快乐数字，则这个数就是快乐的
//求第n个快乐数（1<=n<=1e9)，例如：2，3,263都是，而231不是
#include<stdio.h>
//用于检测每一位是不是快乐数字
int check(long long int a)
{
	int flag = 0;
	long long int ret = 0;
	for (; a > 0; a /= 10) {
		ret = a % 10;
		if (ret != 2 && ret != 3 && ret != 6) {
			flag = 1;
			break;
		}
	}
	return flag;
}
int main()
{
	long long int n = 0;
	scanf("%lld", &n);
	long long int count = 0;//统计到了第几个快乐数
	long long int i = 0;
	int flag = 0;//判断是不是快乐数的指标，0表示是，1表示不是
	for (i = 2; count < n; i++) {
		flag = check(i);
		if (flag == 0) {
			count++;
		}
	}
	i--;
	printf("%lld", i);
	return 0;
}