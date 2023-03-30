#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

//头文件声明
#include<stdio.h>
#include<Windows.h>

//宏定义
#define MAX_NUMBER 1000
#define MAX_NAME 20
#define MAX_ADDRES 40
#define MAX_TELE 12

//枚举定义

enum first_menu_cmd
{
	EXIT,
	ADD,
	DEL,
	SERACH,
	MODIFY,
	PRINT
};//菜单指令


//定义联系人类型

 typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[3];
	char tele[MAX_TELE];
	char destion[MAX_ADDRES];
} PeoInfo;

 //定义通讯录类型
 typedef struct Contatc
 {
	 PeoInfo data[MAX_NUMBER];
	 int sz;
 } Contact;//可以直接使用static修饰，不用套娃

 //函数声明
 void menu();
 void InitContatc(Contact*);
 void add_menu();
 void AddContact(Contact*);
 void DelContact(Contact*);
 static int FindName(Contact*,char*);
 void Print(Contact*);
 void Serach(Contact*);
 void Sort(Contact*);
