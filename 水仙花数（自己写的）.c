#include<stdio.h>

int main()
{
	//确定位数，如n=3，则i=100 
	int n;
	scanf("%d",&n);
	int cnt=1;
	int i=1;
	while(i<n){
		cnt*=10;
		i++;
	}
	i=cnt;
	//定义变量 
	int a=i;
	int cnt2=0;
	int sum=0;
	int sum1=1;
	while(i<a*10){  //使i从对应最小数字开始到最大，如100-999 
		int b=i;
		int c=i;
		while(c>0){  //把每一位拆分
			b%=10;
			c/=10;
			while(cnt2<n){ //求拆分出的数的n次方
				sum1=sum1*b;
				cnt2++;
			}
			sum=sum+sum1;//求所有n次方的和 
			cnt2=0;
			b=c;
			sum1=1;
		}
		if(sum==i){   //判断是否符合水仙花数，输出 
			printf("%d\n",sum);
		}
		sum=0;
		i++;
	}	
	return 0;
}
