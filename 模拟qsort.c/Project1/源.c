#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void test1();
//void test2();
void my_sort(void* base, int sz, int width, int(*cmp_int)(const void* e1, const void* e2));
int cmp_int(const void* e1, const void* e2);
void swap(char* e1, char* e2, int width);
void print(int arr[], int sz);
//int cmp_str_age(const void* e1, const void* e2);

//struct Stu {
//	char name[20];
//	int age;
//};
////���Խṹ��
//void test2()
//{
//	struct Stu s[3] = { {"zhangsan",40},{"lisi",30},{"wangwu",20} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	my_sort(s, sz, sizeof(s[0]), cmp_str_age);
//}
//��������
void test1()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
}
//ģ��ʵ��qsort
void my_sort(void* base, int sz, int width, int (*cmp_int)(const void* e1, const void* e2))//�����Ϳ⺯���е�ȥsort����һ��
{
	int i = 0;
	//����
	for (i = 0; i < sz - 1; i++) {
		//��������
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) {
			//����Ԫ�صıȽ�
			//����void����ֱ�ӱȽϣ�����ͨ��ǿ��ת��Ϊchar*�ӿ���������±�Ϊj��j+1��Ԫ��
			if (cmp_int((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
				//����
				//����ʱҲ��֪����ʲô�ַ�������ͨ��char*�Ϳ����һ���ֽ�һ���ֽڽ���
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
//�ȽϺ���(����)
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
//�ȽϺ���(�ṹ�壬����)
//int cmp_str_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//��������
void swap(char* e1, char* e2, int width)
{
	int i = 0;
	//���ڲ�֪��Ҫ��������ʲô���ͣ�������char*��һ��һ���ֽڵĽ���
	for (i = 0; i < width; i++) {
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
////��ӡ����(����)
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
}
int main()
{
	test1();
	//test2();
	return 0;
}