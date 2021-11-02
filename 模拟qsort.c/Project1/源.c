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
////测试结构体
//void test2()
//{
//	struct Stu s[3] = { {"zhangsan",40},{"lisi",30},{"wangwu",20} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	my_sort(s, sz, sizeof(s[0]), cmp_str_age);
//}
//测试整形
void test1()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
}
//模拟实现qsort
void my_sort(void* base, int sz, int width, int (*cmp_int)(const void* e1, const void* e2))//参数和库函数中的去sort保持一致
{
	int i = 0;
	//趟数
	for (i = 0; i < sz - 1; i++) {
		//交换次数
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) {
			//两个元素的比较
			//由于void不能直接比较，所以通过强制转换为char*加宽度来访问下标为j和j+1的元素
			if (cmp_int((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
				//交换
				//交换时也不知道是什么字符，所以通过char*和宽度来一个字节一个字节交换
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
//比较函数(整型)
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
//比较函数(结构体，年龄)
//int cmp_str_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//交换函数
void swap(char* e1, char* e2, int width)
{
	int i = 0;
	//由于不知道要交换的是什么类型，所以用char*来一个一个字节的交换
	for (i = 0; i < width; i++) {
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
////打印函数(整型)
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