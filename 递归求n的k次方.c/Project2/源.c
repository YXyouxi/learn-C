#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
double DigitSum(int n,int k)
{
	if (k == 0) {
		return 1.0;
	}
	else if (k > 0 ) {
		double sum = n * DigitSum(n, k - 1);
		return sum;
	}
	else if (k < 0) {
		double sum = 1.0 / (DigitSum(n, -k));
		return sum;
	}
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n,&k);
	double sum = DigitSum(n,k);
	printf("%lf", sum);
	return 0;
}

