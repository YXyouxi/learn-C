#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int is_string_rotate(char* str1, char* str2)
{
	//长度不相等，一定不是旋转得到的
	if (strlen(str1) != strlen(str2)){
	return 0;
	}
	else {
		//字符串str1后边追加一个str1,这样所有旋转得来的子串都被包含
		int len = strlen(str1);
		strncat(str1, str1, len);
		char* ret = strstr(str1, str2);
		return ret != NULL;//找到了，则为真，返回1，找不到，则为假，返回0
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