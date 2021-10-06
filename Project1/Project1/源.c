#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//递归实现数组的逆序，不是逆序打印
//求数组的长度
int my_strlen(char* arr)
{
	int cnt = 0;
	while (*arr!='\0') {
		arr++;
		cnt++;
	}
	return cnt;
}
//逆序函数
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
	reverse_str(arr);//逆序函数
	printf("%s", arr);
	return 0;
}
//整个程序通过递归实现
//递归函数具体操作为：如数组为abcdef，则先另取一变量tmp存储a，将f和a调换
//然后将原本f的位置换为'\0'
//之后进行递归，将地址＋1传进去，即传进去了bcde，然后重复操作
// 每次执行完函数返回后，将原本存储在tmp中的字符赋给最后
//当数组的长度等于1或0时代表整个数组都进行了逆序，递归结束