#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void MyStrcpy(char* destination, const char* source)//��const��ֹdestination��sourceд��
{
	assert(source != NULL);//��ֹ���ݵ��ǿ�ָ��
	assert(destination != NULL);
	while (*destination++ = *source++) //�����Ǻ���++�������Ƚ������ټ�1��֪������\0,ASCLL��ֵΪ0,0Ϊ�٣�����ѭ��
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