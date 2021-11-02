#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* up = str1;//存储上一次str1访问的位置
	//如果要查找的字符串是空字符串
	if (*str2 == '\0') {
		return (char*)str1;
	}
	while (*up) {
		s1 = up;
		s2 = str2;//要查找的字符串回到起始位置
		//判断字符是否相同，为\0则代表至少有一个字符串查找完毕
		while (*s1 && *s2 && (*s1 == *s2)) {
			s1++;
			s2++;
		}
		//要查找的字符指向\0，代表查找完了且找到了
		if (*s2 == '\0') {
			return (char*)up;
		}
		up++;//从上一次访问的字符的下一个开始查找
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
		printf("找不到");
	}
	return 0;
}