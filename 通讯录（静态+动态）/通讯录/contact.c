#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//静态版本初始化
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//动态版本初始化
void InitContact(Contact* pc)
{
	pc->data = (PeInfo*)malloc(default_sz * sizeof(PeInfo));//为data申请堆上的空间
	if (pc->data == NULL) {
		perror("InitContact");
		return;
	}
	pc->sz = 0;//初始化后通讯录中人数为0
	pc->capacity = default_sz;//最大容量
}

//销毁
void Destory(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//静态版本增加信息
//void AddContact(Contact* pc)
//{
//	if (pc->sz == MAX) {
//		printf("通讯录已满，无法添加");
//		return;
//	}
//	printf("请输入姓名\n");
//	(void)scanf("%s", pc->data[pc->sz].name);
//	printf("请输入性别\n");
//	(void)scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入年龄\n");
//	(void)scanf("%d", &pc->data[pc->sz].age);
//	printf("请输入电话\n");
//	(void)scanf("%s", pc->data[pc->sz].tele);
//	printf("请输入住址\n");
//	(void)scanf("%s", pc->data[pc->sz].addr);
//	pc->sz++;
//	printf("添加成功\n");
//}

//动态版本增加信息
void AddContact(Contact* pc)
{
	if (pc->sz == pc->capacity) {
		//开辟空间
		PeInfo* ptr= (PeInfo*)realloc(pc->data, (pc->capacity+supply_sz) * sizeof(PeInfo));//开辟supply_sz个容量
		if (ptr == NULL) {
			perror("AddContact");
			printf("增加失败\n");
			return;
		}
		printf("扩容成功\n");
		pc->data = ptr;
		pc->capacity += supply_sz;//最大容量增加supply_sz个
	}
	printf("请输入姓名\n");
	(void)scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别\n");
	(void)scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄\n");
	(void)scanf("%d", &pc->data[pc->sz].age);
	printf("请输入电话\n");
	(void)scanf("%s", pc->data[pc->sz].tele);
	printf("请输入住址\n");
	(void)scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功\n");
}

void PrintContact(const Contact* pc)
{
	int i = 0;
	printf("%-20s %-20s %-20s %-20s %-20s\n", "姓名", "性别", "年龄", "电话", "住址");
	for (i = 0; i < pc->sz; i++) {
		printf("%-20s %-20s %-20d %-20s %-20s\n", pc->data[i].name, 
												  pc->data[i].sex, 
												  pc->data[i].age, 
												  pc->data[i].tele, 
												  pc->data[i].addr);
	}
}

//查找函数
static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;//返回找到的下标
		}
	}
	return -1;//找不到
}

void DelContact(Contact* pc)
{
	char name[max_name];
	if (pc->sz == 0) {
		printf("无可删除数据\n");
		return;
	}
	printf("请输入要删除的人的姓名：\n");
	(void)scanf("%s", name);
	int i = 0;
	//查找要删除的人
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("要删除的人不存在\n");
		return;
	}
	for (i = ret; i < pc->sz-1; i++) {
		pc->data[i] = pc->data[i + 1];//直接将查找到的下标后的人往前挪一位
	}
	pc->sz--;//删除一个人，人数减一
	printf("删除成功\n");
}

void SearchContact(Contact* pc)
{
	char name[max_name];
	if (pc->sz == 0) {
		printf("无可查找数据\n");
		return;
	}
	printf("请输入要查找的人的姓名：\n");
	(void)scanf("%s", name);
	int i = 0;
	//查找要查找的人
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("要查找的人不存在\n");
		return;
	}
	else {
		printf("%-20s %-20s %-20s %-20s %-20s\n", "姓名", "性别", "年龄", "电话", "住址");
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
		printf("无可修改数据\n");
		return;
	}
	printf("请输入要修改的人的姓名：\n");
	(void)scanf("%s", name);
	int i = 0;
	//查找要修改的人
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("要修改的人不存在\n");
		return;
	}
	else {
		printf("请输入姓名\n");
		(void)scanf("%s", pc->data[ret].name);
		printf("请输入性别\n");
		(void)scanf("%s", pc->data[ret].sex);
		printf("请输入年龄\n");
		(void)scanf("%d", &pc->data[ret].age);
		printf("请输入电话\n");
		(void)scanf("%s", pc->data[ret].tele);
		printf("请输入住址\n");
		(void)scanf("%s", pc->data[ret].addr);
	}
}