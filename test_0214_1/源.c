#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
struct bank
{
	char id[8];
	double money;
	char name[20];
	char sf[20];
	char day[20];
} o[2000], n;
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
	case 1:
		est();
		break;
	case 2:
		enter();
		break;
	case 3:
		zhuxiao();
		break;
	case 4:
		tongji();
		break;
	case 5:
		printf("ллʹ��\n");
		break;
	}
}
int read()
{
	int i;
	int n = 0;
	FILE *fp;
	fp = fopen("�˻�.txt", "rb");
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
	printf("                                 1. ע���˻�\n");
	printf("\n");
	printf("                                 2. �����ʻ���¼\n");
	printf("\n");
	printf("                                 3. ע��\n");
	printf("\n");
	printf("                                 4. ͳ��\n");
	printf("\n");
	printf("                                 5. �˳�\n");
	printf("\n");
	printf("=================================================================================\n");
	printf("\n");
}
void mune_2()
{
	printf("=================================BANK OF CONTEC=================================\n");
	printf("                                 1. ��Ǯ\n");
	printf("\n");
	printf("                                 2. ȡǮ\n");
	printf("\n");
	printf("                                 3. ��ѯ\n");
	printf("\n");
	printf("                                 4. ���ز˵�\n");
	printf("\n");
	printf("                                 5. �˳�\n");
	printf("\n");
	printf("=================================================================================\n");
	printf("\n");
}
void est() // ע�����˻�
{
	printf("ע��\n");
	struct bank *p;
	struct bank old[2000];
	p = &n;
	printf("����������id(��λ)\n");
	getchar();
	gets_s(n.id);
	printf("������������֤���룺\n");
	getchar();
	gets_s(n.sf);
	printf("��������������:\n");
	gets_s(n.name);
	printf("����������\n");
	gets_s(n.day);
	printf("ע��ɹ���\n");
	for (;;) // �������
	{
		printf("�����������û����ٴ���100��\n");
		scanf_s("%lf", &n.money);
		if (n.money < 100)
		{
			printf("������С��100��������");
		}
		else
		{
			printf("�����ɹ���\n");
			break;
		}
	}
	FILE *fx;								//
	fx = fopen("�˻�.txt", "a");				//
	if (fx == NULL)							//
	{										//    ������û���Ϣ
		exit(0);							//
	}										//
	fwrite(&n, sizeof(struct bank), 1, fx); //
	fclose(fx);								//
}
int enter() // �������е��˻�
{
	char id[8];
	char b[20];
	int c, d;
	read();
	int n = 0;
	int m = 0;
	for (; n == 0;)
	{
		getchar();
		printf("����������id��\n");
		gets_s(id);
		for (u = 0; u < 2000; u++)
		{
			if (strcmp(id, o[u].id) == 0)
			{
				n = 1;
				m = 1;
				break;
			}
			if (u == 1999)
			{
				printf("δ��ѯ�����˻�\n");
				printf("���µ����밴1��ע���밴2\n");
				scanf("%d", &d);
				if (d == 2)
				{
					return 1;
				}
			}
		}
	}
	printf("����ɹ�\n");
	yewu();
	return 0;
}
void zhuxiao() // ע��
{
	int i;
	struct bank z[2000];
	int n = 0;
	char id[20];
	printf("��������Ҫע���˻���id\n");
	getchar();
	gets_s(id, sizeof(id));
	read();
	for (i = 0; i < 2000; i++)
	{
		if (strcmp(id, o[i].id) == 0)
			break;
		if (i == 1999)
		{
			printf("δ��ѯ�����˻�\n");
		}
	}
	FILE *p;
	p = fopen("�˻�.txt", "w+");
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
void tongji() // ͳ��
{
	read();
	printf("����%d��\n", read() - 1980);
	meun_1();
	menu();
}
void cun(int g) // ��Ǯҵ��
{
	double m;
	printf("����������\n");
	scanf_s("%lf", &m);
	FILE *p;
	p = fopen("�˻�.txt", "w+");
	if (p == NULL)
		exit(0);
	for (int i = 0; i < 200; i++)
	{
		fread(&o[i], sizeof(struct bank), 1, p);
	}
	o[u].money += m;
	printf("����ǰ���Ϊ%lf\n", o[u].money);
	for (int j = 0; j < 200; j++)
	{
		fwrite(&o[j], sizeof(struct bank), 1, p);
	}
	fclose(p);
	yewu();
}
void qu()
{
	printf("����ǰ���Ϊ%lf", o[u].money);
	double m;
	printf("������ȡ����\n");
	scanf_s("%lf", &m);
	FILE *p;
	p = fopen("�˻�.txt", "w+");
	if (p == NULL)
		exit(0);
	for (int i = 0; i < 200; i++)
	{
		fread(&o[i], sizeof(struct bank), 1, p);
	}
	o[u].money -= m;
	printf("����ǰ���Ϊ%lf", o[u].money);
	for (int j = 0; j < 200; j++)
	{
		fwrite(&o[j], sizeof(struct bank), 1, p);
	}
	fclose(p);
	yewu();
}
void chaxun(int x) // ��ѯҵ��
{
	read();
	printf("�����˻���:%s\n", o[u].name);
	printf("���˻����:%lf\n", o[u].money);
	printf("ע������Ϊ:%s\n", o[u].day);
	yewu();
}
void yewu()
{
	int a;
	mune_2();
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		cun(u);
		break;
	case 2:
		qu();
		break;
	case 3:
		chaxun(u);
		break;
	case 4:
		meun_1();
		menu();
	case 5:
		printf("ллʹ��\n");
		exit(0);
	}
}
int main()
{
	meun_1();
	menu();
	return (0);
}