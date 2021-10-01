#include<stdio.h>

int main()
{
	//左三角 
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	//上三角
	int m,n;
	for(m=0;m<5;m++){
		for(n=0;n<4-m;n++){
		printf(" ");
		}
		for(n=0;n<=m;n++){
		printf("*");
		}
		for(n=0;n<m;n++){
		printf("*");
		}
		printf("\n");	
	} 
	printf("\n");
	//下三角
	int a,b;
	for(a=5;a>0;a--){
		for(b=4;b<9-a;b++){
			printf(" ");
		}
		for(b=0;b<a;b++){
			printf("*");
		}
		for(b=0;b<a-1;b++){
			printf("*");
		}
		printf("\n");
	} 
	return 0;
}
