#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int is_string_rotate(char* str1, char* str2)
{
	//���Ȳ���ȣ�һ��������ת�õ���
	if (strlen(str1) != strlen(str2)){
	return 0;
	}
	else {
		//�ַ���str1���׷��һ��str1,����������ת�������Ӵ���������
		int len = strlen(str1);
		strncat(str1, str1, len);
		char* ret = strstr(str1, str2);
		return ret != NULL;//�ҵ��ˣ���Ϊ�棬����1���Ҳ�������Ϊ�٣�����0
	}
}
int main()
{
	char arr[20] = "AABCD";
	char brr[20] = "BCDAA";
	int ret = is_string_rotate(arr, brr);
	if (ret == 1) {
		printf("yes");
	}
	else {
		printf("no");
	}
	return 0;
}