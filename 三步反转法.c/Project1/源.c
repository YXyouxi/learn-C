#define _CRT_SECURE_NO_WARNINGS 1
//将一句话中的单词进行倒置，标点不倒置，比如I like bejing.经过函数后变为bejing. like I
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
	//三步反转法
	//1.将整个字符串翻转（.gnijeb ekil I）
	int len = strlen(arr);
	reverse(arr,arr+len-1);//下标从0开始，所以最后一个字符下标是len-1
	//2.将每个单词翻转（bejing. like I）
	char* start = arr;
	while (*start) {
		char* end = start;
		while (*end != ' ' && *end != '\0') {//一个单词结束的标志要么是空格，要么是\0（最后一个单词）
			end++;//找到结束标志的地址
		}
		reverse(start, end - 1);
		if (*end == ' ') {
			start = end + 1;//字符串还没结束，start从下一个字母开始
		}
		else {
			start = end;//字符串已经结束，让*start=\0结束循环
		}
	}
	printf("%s", arr);
	return 0;
}