#define _CRT_SECURE_NO_WARNINGS 1
#define max 100
#include<stdio.h>
int main()
{
	int A1[max][max];//用户输入第一个矩阵
	int A2[max][max];//用户输入第二个矩阵
	int A3[max][max];//用来存放相乘结果的矩阵
	int n1, m1, n2, m2;//n为行，m为列
	int i = 0;
	int j = 0;
	int k = 0;
	printf("请输入第一个矩阵的行和列:\n");
	scanf("%d %d", &n1, &m1);
	printf("请输入第二个矩阵的行和列:\n");
	scanf("%d %d", &n2, &m2);
	if (m1 != n2) {
		printf("不符合要求\n");
	}
	else {
		for (i = 0; i < n1; i++) {
			printf("请输入第一个矩阵第%d行的数据：\n", i + 1);
			for (j = 0; j <m1; j++) {
				scanf("%d", &A1[i][j]);
			}
		}
		for (i = 0; i < n1; i++) {
			int j = 0;
			printf("请输入第二个矩阵第%d行的数据：\n", i + 1);
			for (j = 0; j < m1; j++) {
				scanf("%d", &A2[i][j]);
			}
		}
		//初始化A3
		for (i = 0; i < n1; i++) {
			for (j = 0; j < m2; j++) {
				A3[i][j] = 0;
			}
		}
		for (i = 0; i < n1; i++) {
			for (j = 0; j < m2; j++) {
				for (k = 0; k < n1; k++) {
					A3[i][j] = A3[i][j] + A1[i][k] * A2[k][j];//矩阵乘法法则，算法是一轮一轮乘起来相加
				}
			}
		}
		printf("结果是：\n");
		for (i = 0; i < n1; i++) {
			for (j = 0; j < m2; j++) {
				printf("%d ", A3[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}