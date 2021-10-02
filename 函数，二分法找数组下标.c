#include<stdio.h>
int search(int arr[],int k,int sz)
{
	int left=0;
	int right=sz-1;
	while(left<=right){
		int mid = (left + right )/2;
		if(arr[mid]>k){
			right = mid -1;
		}else if(arr[mid]<k){
			left = mid + 1;
		}else{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int k=0;
	scanf("%d",&k);
	int sz=sizeof(arr)/sizeof(arr[0]);
	//找到了就返回找到位置的下标。找不到返回-1
	int ret=search(arr,k,sz);
	if(ret==-1){
		printf("找不到\n");
	}else{
		printf("下标是%d \n",ret);
	}
	return 0;
}

