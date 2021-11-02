#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* destination, const void* source, size_t num)
{
	assert(destination && source);
	void* tmp = destination;
	while (num--) {
		*(char*)destination = *(char*)source;
		destination = (char*)destination + 1;
		source = (char*)source + 1;
	}
	return tmp;
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int brr[10] = { 0 };
	my_memcpy(brr, arr, 20);
	return 0;
}