#include<stdio.h>

int main()
{
	//ȷ��λ������n=3����i=100 
	int n;
	scanf("%d",&n);
	int cnt=1;
	int i=1;
	while(i<n){
		cnt*=10;
		i++;
	}
	i=cnt;
	//������� 
	int a=i;
	int cnt2=0;
	int sum=0;
	int sum1=1;
	while(i<a*10){  //ʹi�Ӷ�Ӧ��С���ֿ�ʼ�������100-999 
		int b=i;
		int c=i;
		while(c>0){  //��ÿһλ���
			b%=10;
			c/=10;
			while(cnt2<n){ //���ֳ�������n�η�
				sum1=sum1*b;
				cnt2++;
			}
			sum=sum+sum1;//������n�η��ĺ� 
			cnt2=0;
			b=c;
			sum1=1;
		}
		if(sum==i){   //�ж��Ƿ����ˮ�ɻ�������� 
			printf("%d\n",sum);
		}
		sum=0;
		i++;
	}	
	return 0;
}
