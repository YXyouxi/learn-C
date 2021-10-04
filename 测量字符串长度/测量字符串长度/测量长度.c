#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int my_strlen(char* arr)
{
	if (*arr !='\0') {
		return 1 + my_strlen(arr+1);
	}
	else {
		return 0;
	}
}
int main()
{
	char arr[20];
	scanf("%s", arr);
		//实现strlen函数递归求字符串长度
		printf("%d\n", my_strlen(arr));
	return 0;
}