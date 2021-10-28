#define _CRT_SECURE_NO_WARNINGS 1
//左旋一个字符串，如ABCD左旋1变为BCDA
#include<stdio.h>
#include<string.h>
//逆序函数
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
//分为三步逆序
//解释：如ABCDEF，左旋2单位，则先将AB逆序，再将CDEF逆序，变为BAFEDC，再整体逆序，就变成了CDEFAB
void left_move(char* left, int k,int len)
{
	reverse(left, left + k - 1);//前k个元素逆序
	reverse(left + k , left + len - 1);//后边元素逆序
	reverse(left, left + len - 1);//整体逆序
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