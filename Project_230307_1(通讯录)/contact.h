#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

//ͷ�ļ�����
#include<stdio.h>
#include<Windows.h>

//�궨��
#define MAX_NUMBER 1000
#define MAX_NAME 20
#define MAX_ADDRES 40
#define MAX_TELE 12

//ö�ٶ���

enum first_menu_cmd
{
	EXIT,
	ADD,
	DEL,
	SERACH,
	MODIFY,
	PRINT
};//�˵�ָ��


//������ϵ������

 typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[3];
	char tele[MAX_TELE];
	char destion[MAX_ADDRES];
} PeoInfo;

 //����ͨѶ¼����
 typedef struct Contatc
 {
	 PeoInfo data[MAX_NUMBER];
	 int sz;
 } Contact;//����ֱ��ʹ��static���Σ���������

 //��������
 void menu();
 void InitContatc(Contact*);
 void add_menu();
 void AddContact(Contact*);
 void DelContact(Contact*);
 static int FindName(Contact*,char*);
 void Print(Contact*);
 void Serach(Contact*);
 void Sort(Contact*);
