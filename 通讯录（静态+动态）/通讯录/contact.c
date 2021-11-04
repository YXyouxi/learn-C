#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//��̬�汾��ʼ��
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//��̬�汾��ʼ��
void InitContact(Contact* pc)
{
	pc->data = (PeInfo*)malloc(default_sz * sizeof(PeInfo));//Ϊdata������ϵĿռ�
	if (pc->data == NULL) {
		perror("InitContact");
		return;
	}
	pc->sz = 0;//��ʼ����ͨѶ¼������Ϊ0
	pc->capacity = default_sz;//�������
}

//����
void Destory(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//��̬�汾������Ϣ
//void AddContact(Contact* pc)
//{
//	if (pc->sz == MAX) {
//		printf("ͨѶ¼�������޷����");
//		return;
//	}
//	printf("����������\n");
//	(void)scanf("%s", pc->data[pc->sz].name);
//	printf("�������Ա�\n");
//	(void)scanf("%s", pc->data[pc->sz].sex);
//	printf("����������\n");
//	(void)scanf("%d", &pc->data[pc->sz].age);
//	printf("������绰\n");
//	(void)scanf("%s", pc->data[pc->sz].tele);
//	printf("������סַ\n");
//	(void)scanf("%s", pc->data[pc->sz].addr);
//	pc->sz++;
//	printf("��ӳɹ�\n");
//}

//��̬�汾������Ϣ
void AddContact(Contact* pc)
{
	if (pc->sz == pc->capacity) {
		//���ٿռ�
		PeInfo* ptr= (PeInfo*)realloc(pc->data, (pc->capacity+supply_sz) * sizeof(PeInfo));//����supply_sz������
		if (ptr == NULL) {
			perror("AddContact");
			printf("����ʧ��\n");
			return;
		}
		printf("���ݳɹ�\n");
		pc->data = ptr;
		pc->capacity += supply_sz;//�����������supply_sz��
	}
	printf("����������\n");
	(void)scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�\n");
	(void)scanf("%s", pc->data[pc->sz].sex);
	printf("����������\n");
	(void)scanf("%d", &pc->data[pc->sz].age);
	printf("������绰\n");
	(void)scanf("%s", pc->data[pc->sz].tele);
	printf("������סַ\n");
	(void)scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�\n");
}

void PrintContact(const Contact* pc)
{
	int i = 0;
	printf("%-20s %-20s %-20s %-20s %-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
	for (i = 0; i < pc->sz; i++) {
		printf("%-20s %-20s %-20d %-20s %-20s\n", pc->data[i].name, 
												  pc->data[i].sex, 
												  pc->data[i].age, 
												  pc->data[i].tele, 
												  pc->data[i].addr);
	}
}

//���Һ���
static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;//�����ҵ����±�
		}
	}
	return -1;//�Ҳ���
}

void DelContact(Contact* pc)
{
	char name[max_name];
	if (pc->sz == 0) {
		printf("�޿�ɾ������\n");
		return;
	}
	printf("������Ҫɾ�����˵�������\n");
	(void)scanf("%s", name);
	int i = 0;
	//����Ҫɾ������
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	for (i = ret; i < pc->sz-1; i++) {
		pc->data[i] = pc->data[i + 1];//ֱ�ӽ����ҵ����±�������ǰŲһλ
	}
	pc->sz--;//ɾ��һ���ˣ�������һ
	printf("ɾ���ɹ�\n");
}

void SearchContact(Contact* pc)
{
	char name[max_name];
	if (pc->sz == 0) {
		printf("�޿ɲ�������\n");
		return;
	}
	printf("������Ҫ���ҵ��˵�������\n");
	(void)scanf("%s", name);
	int i = 0;
	//����Ҫ���ҵ���
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else {
		printf("%-20s %-20s %-20s %-20s %-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
		printf("%-20s %-20s %-20d %-20s %-20s\n", pc->data[ret].name,
												  pc->data[ret].sex,
												  pc->data[ret].age,
												  pc->data[ret].tele,
												  pc->data[ret].addr);
	}
}

void ModifyContact(Contact* pc)
{
	char name[max_name];
	if (pc->sz == 0) {
		printf("�޿��޸�����\n");
		return;
	}
	printf("������Ҫ�޸ĵ��˵�������\n");
	(void)scanf("%s", name);
	int i = 0;
	//����Ҫ�޸ĵ���
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else {
		printf("����������\n");
		(void)scanf("%s", pc->data[ret].name);
		printf("�������Ա�\n");
		(void)scanf("%s", pc->data[ret].sex);
		printf("����������\n");
		(void)scanf("%d", &pc->data[ret].age);
		printf("������绰\n");
		(void)scanf("%s", pc->data[ret].tele);
		printf("������סַ\n");
		(void)scanf("%s", pc->data[ret].addr);
	}
}