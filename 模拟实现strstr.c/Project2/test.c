#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* up = str1;//�洢��һ��str1���ʵ�λ��
	//���Ҫ���ҵ��ַ����ǿ��ַ���
	if (*str2 == '\0') {
		return (char*)str1;
	}
	while (*up) {
		s1 = up;
		s2 = str2;//Ҫ���ҵ��ַ����ص���ʼλ��
		//�ж��ַ��Ƿ���ͬ��Ϊ\0�����������һ���ַ����������
		while (*s1 && *s2 && (*s1 == *s2)) {
			s1++;
			s2++;
		}
		//Ҫ���ҵ��ַ�ָ��\0����������������ҵ���
		if (*s2 == '\0') {
			return (char*)up;
		}
		up++;//����һ�η��ʵ��ַ�����һ����ʼ����
	}
	return NULL;
}
int main()
{
	char arr[] = "abbbcdef";
	char brr[] = "bbc";
	char* ret = my_strstr(arr, brr);
	if (ret!=NULL) {
		printf("%s", ret);
	}
	else {
		printf("�Ҳ���");
	}
	return 0;
}