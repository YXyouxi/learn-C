#define _CRT_SECURE_NO_WARNINGS 1
#define max 100
#include<stdio.h>
int main()
{
	int A1[max][max];//�û������һ������
	int A2[max][max];//�û�����ڶ�������
	int A3[max][max];//���������˽���ľ���
	int n1, m1, n2, m2;//nΪ�У�mΪ��
	int i = 0;
	int j = 0;
	int k = 0;
	printf("�������һ��������к���:\n");
	scanf("%d %d", &n1, &m1);
	printf("������ڶ���������к���:\n");
	scanf("%d %d", &n2, &m2);
	if (m1 != n2) {
		printf("������Ҫ��\n");
	}
	else {
		for (i = 0; i < n1; i++) {
			printf("�������һ�������%d�е����ݣ�\n", i + 1);
			for (j = 0; j <m1; j++) {
				scanf("%d", &A1[i][j]);
			}
		}
		for (i = 0; i < n1; i++) {
			int j = 0;
			printf("������ڶ��������%d�е����ݣ�\n", i + 1);
			for (j = 0; j < m1; j++) {
				scanf("%d", &A2[i][j]);
			}
		}
		//��ʼ��A3
		for (i = 0; i < n1; i++) {
			for (j = 0; j < m2; j++) {
				A3[i][j] = 0;
			}
		}
		for (i = 0; i < n1; i++) {
			for (j = 0; j < m2; j++) {
				for (k = 0; k < n1; k++) {
					A3[i][j] = A3[i][j] + A1[i][k] * A2[k][j];//����˷������㷨��һ��һ�ֳ��������
				}
			}
		}
		printf("����ǣ�\n");
		for (i = 0; i < n1; i++) {
			for (j = 0; j < m2; j++) {
				printf("%d ", A3[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}