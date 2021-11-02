#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void* my_memmove(void* destination, const void* source, size_t num)
{
	assert(destination && source);
	void* tmp = destination;
	if (destination < source) {
		//从前向后拷贝
		while (num--) {
			*(char*)destination = *(char*)source;
			destination = (char*)destination + 1;
			source = (char*)source + 1;
		}
	}
	else {
		//从后向前拷贝
		while (num--) {
			*((char*)destination + num) = *((char*)source + num);
		}
	}
	return tmp;
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr, arr+4, 20);
	return 0;
}