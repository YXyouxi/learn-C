#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	int i;
	scanf("%d", &n);
	int arr[10] = { 0 };
	while (n != -1) {
		if (n >= 0 && n <= 9) {
			arr[n]++;
		}
		scanf("%d", &n);
	}
	for (i = 0; i <= 9; i++) {
		printf("%d:%d\n", i, arr[i]);
	}
	
	return 0;
}