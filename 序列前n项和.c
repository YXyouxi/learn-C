#include<stdio.h>

int main()
{
	int a=1;
	int b=2;
	int n;
	scanf("%d",&n);
	int cnt=1;
	int k=1;
	double sum=0;
	double i=a+b;
	double j=b;
	for(;cnt<=n-1;cnt++){
		int c=i;
		if(n==1){
			k=0;
		}else{
			sum=sum+i/j;
			i=i+j;
			j=c;
		}
		
	}
	if(k==0){
		printf("%.2lf",2.0/1);
	}else{
		printf("%.2lf",sum+2.0/1);
	}
	return 0;
}
