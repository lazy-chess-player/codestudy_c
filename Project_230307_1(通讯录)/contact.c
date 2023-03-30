#include"contact.h"
//���˵�
void menu()
{
	system("cls");
	printf("            ͨѶ¼            \n\n\n");
	printf("1���½���ϵ��\n");
	printf("2��ɾ����ϵ��\n");
	printf("3��������ϵ��\n");
	printf("4���޸���ϵ��\n");
	printf("5��չʾ��ϵ��\n");
	printf("0���˳�\n\n\n");
	printf("��ѡ��->");
}

//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//�½���ϵ��
void AddContact(Contact* pc)
{
add_start:
	system("cls");
	printf("           �½���ϵ��           \n\n\n");

	add_menu();
	if (pc->sz >= MAX_NUMBER)
	{
		printf("ͨѶ¼��������ɾ�����½���ϵ��");
		return 0;
	}

	//������Ϣ
	printf("����������->");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������->");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�->");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰->");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ->");
	scanf("%s", pc->data[pc->sz].destion);
	pc->sz++;//������ɺ����

	//�ж��Ƿ���Ҫ��������
	char cmd_add;
	while (1)
	{
		printf("��ϵ�������ɣ��Ƿ������ӣ�(Y���������������)\n");
		printf("������->");
		getchar();
		scanf("%c", &cmd_add);
		if(cmd_add==89||cmd_add==121)
			goto add_start;
		else
			break;
	}
};

//������ϵ��
static int FindName(Contact* pc, char* name)
{
	system("cls");
	printf("           ������ϵ��           \n\n\n");

	int i = 0;
	for (; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

//ɾ����ϵ��
void DelContact(Contact* pc)
{
	system("cls");
	printf("           ɾ����ϵ��           \n\n\n");

	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ����\n");
		return 0;
	}

	//1�������Ƿ������Ҫɾ������
	char name[MAX_NAME];
	printf("����������->");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("����ϵ�˲�����");
		return 0;
	}

	//2��ɾ��
	for (int i = pos; i < pc->sz; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");

	printf("���������\n");
	getch();
}

//չʾ��ϵ��
void Print(Contact* pc)
{
	system("cls");
	printf("           չʾ��ϵ��           \n\n\n");

	printf("����      ����   �Ա�   �绰         ��ַ\n");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%s      %d   %s   %s         %s\n",pc->data[i].name,pc->data[i].age,pc->data[i].sex,pc->data[i].tele,pc->data[i].destion);
	}

	printf("���������\n");
	getch();
};

//������ϵ��
void Serach(Contact* pc)
{
	system("cls");
	printf("           ������ϵ��           \n\n\n");

	char name[MAX_NAME];
	printf("�������������ϵ�˵�����->");
	scanf("%s", name);
	int i = FindName(pc, name);
	if (i == -1)
		printf("��������ϵ�ˡ�");
	else
	{
		printf("����      ����   �Ա�   �绰         ��ַ\n");
		printf("%s      %d   %s   %s         %s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].destion);
	}

	printf("���������\n");
	getch();
}

//�޸���ϵ��
void Modify(Contact* pc)
{
	system("cls");
	printf("           �޸���ϵ��           \n\n\n");

	char name[MAX_NAME];
	printf("���������޸���ϵ�˵�����->");
	scanf("%s", name);
	int i = FindName(pc, name);
	if (i == -1)
		printf("��������ϵ�ˡ�");
	else
	{
		printf("����������->");
		scanf("%s", pc->data[i].name);
		printf("����������->");
		scanf("%d", &(pc->data[i].age));
		printf("�������Ա�->");
		scanf("%s", pc->data[i].sex);
		printf("������绰->");
		scanf("%s", pc->data[i].tele);
		printf("�������ַ->");
		scanf("%s", pc->data[i].destion);
	}

	printf("���������\n");
	getch();
}