#define _CRT_SECURE_NO_WARNINGS 1
//����һ���ַ�������ABCD����1��ΪBCDA
#include<stdio.h>
#include<string.h>
//������
void reverse(char* left, char* right)
{
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
//��Ϊ��������
//���ͣ���ABCDEF������2��λ�����Ƚ�AB�����ٽ�CDEF���򣬱�ΪBAFEDC�����������򣬾ͱ����CDEFAB
void left_move(char* left, int k,int len)
{
	reverse(left, left + k - 1);//ǰk��Ԫ������
	reverse(left + k , left + len - 1);//���Ԫ������
	reverse(left, left + len - 1);//��������
}
int main()
{
	char arr[10] = "ABCDEF";
	int k = 0;
	scanf("%d", &k);
	int len = strlen(arr);
	left_move(arr, k,len);
	printf("%s", arr);
	return 0;
}