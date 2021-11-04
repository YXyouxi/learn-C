#pragma once
//通讯录
//能够存放1000人的信息
//每个人：
//名字+性别+年龄+电话+住址
//可以实现的功能：
//1.增加人的信息
//2.删除指定人的信息
//3.修改指定人的信息
//4.查找指定人的信息
//5.显示指定人的信息
//6.排序

#include<stdio.h>
#include<string.h>

#define max_name 20
#define max_sex 10
#define max_addr 30
#define max_tele 20
#define MAX 1000

//类型的定义
typedef struct PeInfo
{
	char name[max_name];
	char sex[max_sex];
	int age;
	char tele[max_tele];
	char addr[max_addr];
}PeInfo;

//通讯录
typedef struct Contact
{
	PeInfo data [MAX];//存放信息
	int sz;//记录人数
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//增加信息
void AddContact(Contact* pc);

//显示信息
void PrintContact(const Contact* pc);

//删除信息
void DelContact(Contact* pc);

//查找信息
void SearchContact(Contact* pc);

//修改信息
void ModifyContact(Contact* pc);