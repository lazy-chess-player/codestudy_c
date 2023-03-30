#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
struct bank {
	char id[8];
	double money;
	char name[20];
	char sf[20];
	char day[20];
}o[2000], n;
int u;
int v = 0;
void yewu();
void est();
void tongji();
void zhuxiao();
void meun_1();
void menu()
{
	int a;
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:est(); break;
	case 2:enter();
		break;
	case 3:zhuxiao(); break;
	case 4:tongji(); break;
	case 5:printf("谢谢使用\n"); break;
	}
}
int read()
{
	int i;
	int n = 0;
	FILE* fp;
	fp = fopen("账户.txt", "rb");
	if (fp == NULL)
	{
		exit(0);
	}
	for (i = 0;; i++)
	{
		fread(&o[i], sizeof(struct bank), 1, fp);
		if (feof(fp) == 1)
		{
			break;
		}
	}
	fclose(fp);
	return (i + 1);
}
void meun_1()
{

	printf("=================================BANK OF CONTEC=================================\n");
	printf("                                 1. 注册账户\n");
	printf("\n");
	printf("                                 2. 已有帐户登录\n");
	printf("\n");
	printf("                                 3. 注销\n");
	printf("\n");
	printf("                                 4. 统计\n");
	printf("\n");
	printf("                                 5. 退出\n");
	printf("\n");
	printf("=================================================================================\n");
	printf("\n");
}
void mune_2()
{
	printf("=================================BANK OF CONTEC=================================\n");
	printf("                                 1. 存钱\n");
	printf("\n");
	printf("                                 2. 取钱\n");
	printf("\n");
	printf("                                 3. 查询\n");
	printf("\n");
	printf("                                 4. 返回菜单\n");
	printf("\n");
	printf("                                 5. 退出\n");
	printf("\n");
	printf("=================================================================================\n");
	printf("\n");
}
void est()//注册新账户
{
	printf("注册\n");
	struct bank* p; struct bank old[2000];
	p = &n;
	printf("请输入您的id(七位)\n");
	getchar();
	gets_s(n.id);
	printf("输入您的身份证号码：\n");
	getchar();
	gets_s(n.sf);
	printf("请输入您的名字:\n");
	gets_s(n.name);
	printf("请输入日期\n");
	gets_s(n.day);
	printf("注册成功！\n");
	for (;;)//开户存款
	{
		printf("输入存入金额（新用户最少存入100）\n");
		scanf_s("%lf", &n.money);
		if (n.money < 100)
		{
			printf("存入金额小于100，请重新");
		}
		else
		{
			printf("开户成功！\n"); break;
		}
	}
	FILE* fx;                              //
	fx = fopen("账户.txt", "a");           //
	if (fx == NULL)                           //
	{                                       //    保存存用户信息
		exit(0);                            //
	}                                       //
	fwrite(&n, sizeof(struct bank), 1, fx); //
	fclose(fx);                             // 

}
int enter()//登入已有的账户
{
	char id[8];
	char b[20];
	int c, d;
	read();
	int n = 0; int m = 0;
	for (; n == 0;)
	{
		getchar();
		printf("请输入您的id：\n");
		gets_s(id);
		for (u = 0; u < 2000; u++)
		{
			if (strcmp(id, o[u].id) == 0)
			{
				n = 1; m = 1; break;
			}
			if (u == 1999)
			{
				printf("未查询到该账户\n");
				printf("重新登入请按1，注册请按2\n"); scanf("%d", &d);
				if (d == 2)
				{
					return 1;
				}
			}
		}
	}
	printf("登入成功\n");
	yewu();
	return 0;
}
void zhuxiao()//注销
{
	int i;
	struct bank z[2000]; int n = 0;
	char id[20];
	printf("请输入您要注销账户的id\n");
	getchar();
	gets_s(id, sizeof(id));
	read();
	for (i = 0; i < 2000; i++)
	{
		if (strcmp(id, o[i].id) == 0)
			break;
		if (i == 1999)
		{
			printf("未查询到该账户\n");
		}
	}
	FILE* p;
	p = fopen("账户.txt", "w+");
	for (i; i < 2000; i++)
	{
		o[i] = o[i + 1];
	}
	for (int i = 0; i < 2000; i++)
	{
		fwrite(&o[i], sizeof(struct bank), 1, p);
	}
	fclose(p);
}
void tongji()//统计
{
	read();
	printf("共有%d户\n", read() - 1980);
	meun_1(); menu();
}
void cun(int g)//存钱业务
{
	double m;
	printf("请输入存入金额：\n");
	scanf_s("%lf", &m);
	FILE* p;
	p = fopen("账户.txt", "w+");
	if (p == NULL)
		exit(0);
	for (int i = 0; i < 200; i++)
	{
		fread(&o[i], sizeof(struct bank), 1, p);
	}
	o[u].money += m;
	printf("您当前余额为%lf\n", o[u].money);
	for (int j = 0; j < 200; j++)
	{
		fwrite(&o[j], sizeof(struct bank), 1, p);
	}
	fclose(p);
	yewu();
}
void qu()
{
	printf("您当前余额为%lf", o[u].money);
	double m;
	printf("请输入取出金额：\n");
	scanf_s("%lf", &m);
	FILE* p;
	p = fopen("账户.txt", "w+");
	if (p == NULL)
		exit(0);
	for (int i = 0; i < 200; i++)
	{
		fread(&o[i], sizeof(struct bank), 1, p);
	}
	o[u].money -= m;
	printf("您当前余额为%lf", o[u].money);
	for (int j = 0; j < 200; j++)
	{
		fwrite(&o[j], sizeof(struct bank), 1, p);
	}
	fclose(p);
	yewu();
}
void chaxun(int x)//查询业务
{
	read();
	printf("您的账户名:%s\n", o[u].name);
	printf("您账户余额:%lf\n", o[u].money);
	printf("注册日期为:%s\n", o[u].day);
	yewu();
}
void yewu()
{
	int a;
	mune_2();
	scanf("%d", &a);
	switch (a)
	{
	case 1:cun(u); break;
	case 2:qu(); break;
	case 3:chaxun(u); break;
	case 4: meun_1(); menu();
	case 5:printf("谢谢使用\n"); exit(0);
	}
}
int main()
{
	meun_1();
	menu();
	return(0);
}