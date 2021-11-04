#pragma once
//ͨѶ¼
//�ܹ����1000�˵���Ϣ
//ÿ���ˣ�
//����+�Ա�+����+�绰+סַ
//����ʵ�ֵĹ��ܣ�
//1.�����˵���Ϣ
//2.ɾ��ָ���˵���Ϣ
//3.�޸�ָ���˵���Ϣ
//4.����ָ���˵���Ϣ
//5.��ʾָ���˵���Ϣ
//6.����

#include<stdio.h>
#include<string.h>

#define max_name 20
#define max_sex 10
#define max_addr 30
#define max_tele 20
#define MAX 1000

//���͵Ķ���
typedef struct PeInfo
{
	char name[max_name];
	char sex[max_sex];
	int age;
	char tele[max_tele];
	char addr[max_addr];
}PeInfo;

//ͨѶ¼
typedef struct Contact
{
	PeInfo data [MAX];//�����Ϣ
	int sz;//��¼����
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������Ϣ
void AddContact(Contact* pc);

//��ʾ��Ϣ
void PrintContact(const Contact* pc);

//ɾ����Ϣ
void DelContact(Contact* pc);

//������Ϣ
void SearchContact(Contact* pc);

//�޸���Ϣ
void ModifyContact(Contact* pc);