#include<stdio.h>

int main()
{
	int a,b;	//���巶Χ[a,b] 
	int cnt=0;  //�����ĸ��� 
	int sum=0;  //��� 
	int d=1;    //d=1������������d=0���������� 
	scanf("%d %d",&a,&b); 
	//��a�жϵ�b 
	for(;a<=b;a++){
		//�޳���1��1���������� 
		if(a==1){
			a=2;
		}
		int i=2;//��2��ʼ���������������Ļ���������Ϊ0 
		//i��2��ʼ��a-1 
		for(;i<a;i++){
			int c=a%i;
			//�ж������Ƿ�Ϊ0 
			if(c==0){
				d=0;
				break;//һ����0��ֱ���ų� 
			}
		}
		//���������������һ���ܺͼ�a 
		if(d==1){
			cnt++;
			sum=sum+a;
		}
		d=1;
	}
	printf("%d %d",cnt,sum);
	return 0;
}
