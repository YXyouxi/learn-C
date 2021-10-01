#include<stdio.h>

int main()
{
	int a,b;	//定义范围[a,b] 
	int cnt=0;  //素数的个数 
	int sum=0;  //求和 
	int d=1;    //d=1代表是素数，d=0代表不是素数 
	scanf("%d %d",&a,&b); 
	//从a判断到b 
	for(;a<=b;a++){
		//剔除掉1（1不是素数） 
		if(a==1){
			a=2;
		}
		int i=2;//从2开始求余数，是素数的话余数均不为0 
		//i从2开始到a-1 
		for(;i<a;i++){
			int c=a%i;
			//判断余数是否为0 
			if(c==0){
				d=0;
				break;//一个是0则直接排除 
			}
		}
		//是素数，则计数加一，总和加a 
		if(d==1){
			cnt++;
			sum=sum+a;
		}
		d=1;
	}
	printf("%d %d",cnt,sum);
	return 0;
}
