#define _CRT_SECURE_NO_WARNINGS 1
//��ѡ2,3,6Ϊ�������֣�һ��������ʮ���Ʊ�ʾ��ֻ�����������֣�����������ǿ��ֵ�
//���n����������1<=n<=1e9)�����磺2��3,263���ǣ���231����
#include<stdio.h>
//���ڼ��ÿһλ�ǲ��ǿ�������
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
	long long int count = 0;//ͳ�Ƶ��˵ڼ���������
	long long int i = 0;
	int flag = 0;//�ж��ǲ��ǿ�������ָ�꣬0��ʾ�ǣ�1��ʾ����
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