#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ݹ�ʵ����������򣬲��������ӡ
//������ĳ���
int my_strlen(char* arr)
{
	int cnt = 0;
	while (*arr!='\0') {
		arr++;
		cnt++;
	}
	return cnt;
}
//������
void reverse_str(char* arr)
{
	char tmp = *arr;
	int len = my_strlen(arr) - 1;
	*arr = *(arr + len );
	*(arr + len ) = '\0';
	if (len>1) {
		reverse_str( arr+1);
	}
	*(arr + len ) = tmp;
}
int main()
{
	char arr[20] = { 0 };
	scanf("%s", arr);
	reverse_str(arr);//������
	printf("%s", arr);
	return 0;
}
//��������ͨ���ݹ�ʵ��
//�ݹ麯���������Ϊ��������Ϊabcdef��������ȡһ����tmp�洢a����f��a����
//Ȼ��ԭ��f��λ�û�Ϊ'\0'
//֮����еݹ飬����ַ��1����ȥ��������ȥ��bcde��Ȼ���ظ�����
// ÿ��ִ���꺯�����غ󣬽�ԭ���洢��tmp�е��ַ��������
//������ĳ��ȵ���1��0ʱ�����������鶼���������򣬵ݹ����