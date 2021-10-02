#include<stdio.h>

int main(){
	const char a='*';
	int n=5;
	int j=n;
	int k=n;
	int i=4;
	int b=i;
	int c=5;
	for(;j>0;j--){
		for(;b>0;b--){
			printf(" ");
		}
		for(;c<=5;c++){
			printf("%c",a);
		}
		if(c>5){
			printf("\n");
		}
		i--;
		b=i;
		k--;
		c=k;
	}
	printf("\n");
	j=5;;
	b=4;
	i=4;
	int d=4;
	c=9;
	k=9;
	for(;j>0;j--){
		for(;b>0;b--){
			printf(" ");
		}
		for(;c<=9;c++){
			printf("%c",a);
		}
		c=k;
		for(;c<9;c++){
			printf("%c",a);
		}
		c++;
		for(;d>0;d--){
			printf(" ");
		}
		if(c>9){
			printf("\n");
		}
		i--;
		b=i;
		d=i;
		k--;
		c=k;
	}
	return (0);
} 
