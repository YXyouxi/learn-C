#define _CRT_SECURE_NO_WARNINGS 1
//��һ�仰�еĵ��ʽ��е��ã���㲻���ã�����I like bejing.�����������Ϊbejing. like I
#include<stdio.h>
#include<string.h>
void reverse(char* left,char* right)
{
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main()
{
	char arr[100] = { 0 };
	gets(arr);
	//������ת��
	//1.�������ַ�����ת��.gnijeb ekil I��
	int len = strlen(arr);
	reverse(arr,arr+len-1);//�±��0��ʼ���������һ���ַ��±���len-1
	//2.��ÿ�����ʷ�ת��bejing. like I��
	char* start = arr;
	while (*start) {
		char* end = start;
		while (*end != ' ' && *end != '\0') {//һ�����ʽ����ı�־Ҫô�ǿո�Ҫô��\0�����һ�����ʣ�
			end++;//�ҵ�������־�ĵ�ַ
		}
		reverse(start, end - 1);
		if (*end == ' ') {
			start = end + 1;//�ַ�����û������start����һ����ĸ��ʼ
		}
		else {
			start = end;//�ַ����Ѿ���������*start=\0����ѭ��
		}
	}
	printf("%s", arr);
	return 0;
}