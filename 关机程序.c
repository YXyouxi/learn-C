#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char input[20]={0};
	system("shutdown -s -t 60");//ϵͳ���� ,��Ҫ#include<stdlib.h>ͷ�ļ� 
again:
	printf("���ĵ��Խ�����60���ػ������룺��������ȡ���ػ�\n"); 
	scanf("%s",input);//��Ϊinput�����飬����Ҫȡ��ַ
	if(strcmp(input,"������")==0){    //strcmp���Ƚ������ַ����Ƿ���ͬ����Ҫ#include<string.h>ͷ�ļ� 
		system("shutdown -a");
	}
	else{
		goto again;
	}
	return 0;
}
