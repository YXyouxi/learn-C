#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void MyStrcpy(char* destination, const char* source)//加const防止destination和source写反
{
	assert(source != NULL);//防止传递的是空指针
	assert(destination != NULL);
	while (*destination++ = *source++) //由于是后置++，所以先交换，再加1，知道交换\0,ASCLL码值为0,0为假，跳出循环
	{

	}
}
int main()
{
	char arr1[20] = "abcdefghijk";
	char arr2[] = "MyStrcpy";
	MyStrcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}