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

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define default_sz 3//动态版本初始通讯录大小
#define supply_sz 2//动态版本每次增加的大小
#define max_name 20//名字容量
#define max_sex 10//性别容量
#define max_addr 30//住址容量
#define max_tele 20//电话容量
#define MAX 1000//静态版本最大容量

//类型的定义
typedef struct PeInfo
{
	char name[max_name];
	char sex[max_sex];
	int age;
	char tele[max_tele];
	char addr[max_addr];
}PeInfo;

//通讯录—静态版本
//typedef struct Contact
//{
//	PeInfo data [MAX];//存放信息
//	int sz;//记录人数
//}Contact;

//通讯录—动态内存分配版本
typedef struct Contact
{
	PeInfo* data;//指向动态申请的空间
	int sz;//当前通讯录中的人数
	int capacity;//记录当前通讯录的最大容量
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

//销毁通讯录
void Destory(Contact* pc);