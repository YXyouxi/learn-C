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

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define default_sz 3//��̬�汾��ʼͨѶ¼��С
#define supply_sz 2//��̬�汾ÿ�����ӵĴ�С
#define max_name 20//��������
#define max_sex 10//�Ա�����
#define max_addr 30//סַ����
#define max_tele 20//�绰����
#define MAX 1000//��̬�汾�������

//���͵Ķ���
typedef struct PeInfo
{
	char name[max_name];
	char sex[max_sex];
	int age;
	char tele[max_tele];
	char addr[max_addr];
}PeInfo;

//ͨѶ¼����̬�汾
//typedef struct Contact
//{
//	PeInfo data [MAX];//�����Ϣ
//	int sz;//��¼����
//}Contact;

//ͨѶ¼����̬�ڴ����汾
typedef struct Contact
{
	PeInfo* data;//ָ��̬����Ŀռ�
	int sz;//��ǰͨѶ¼�е�����
	int capacity;//��¼��ǰͨѶ¼���������
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

//����ͨѶ¼
void Destory(Contact* pc);