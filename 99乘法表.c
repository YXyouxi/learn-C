#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i=1;//里边的数，如1*3=3中的3 
	int j=1;//外边的数，如1*3=3中的1 
	//里边从1到n 
	while(i<=n){
		//外边从1到n 
		while(j<=i){
			printf("%d*%d=%-4d",j,i,i*j);
			//对应乘法全部结束，换行，如1*2=2  2*2=4  换行		
			if(i==j){
				printf("\n");
			}
			j++;//外边的数从1开始加 
		}
		i++;//里边的数从1开始加 
		j=1;//另外边的数再次为1 
	}
	return 0;
}
