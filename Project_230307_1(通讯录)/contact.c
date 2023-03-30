#include"contact.h"
//主菜单
void menu()
{
	system("cls");
	printf("            通讯录            \n\n\n");
	printf("1、新建联系人\n");
	printf("2、删除联系人\n");
	printf("3、查找联系人\n");
	printf("4、修改联系人\n");
	printf("5、展示联系人\n");
	printf("0、退出\n\n\n");
	printf("请选择->");
}

//初始化通讯录
void InitContact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//新建联系人
void AddContact(Contact* pc)
{
add_start:
	system("cls");
	printf("           新建联系人           \n\n\n");

	add_menu();
	if (pc->sz >= MAX_NUMBER)
	{
		printf("通讯录已满，请删除后新建联系人");
		return 0;
	}

	//输入信息
	printf("请输入名字->");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄->");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别->");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话->");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址->");
	scanf("%s", pc->data[pc->sz].destion);
	pc->sz++;//输入完成后递增

	//判断是否需要继续输入
	char cmd_add;
	while (1)
	{
		printf("联系人添加完成，是否继续添加？(Y继续，任意键返回)\n");
		printf("请输入->");
		getchar();
		scanf("%c", &cmd_add);
		if(cmd_add==89||cmd_add==121)
			goto add_start;
		else
			break;
	}
};

//查找联系人
static int FindName(Contact* pc, char* name)
{
	system("cls");
	printf("           查找联系人           \n\n\n");

	int i = 0;
	for (; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

//删除联系人
void DelContact(Contact* pc)
{
	system("cls");
	printf("           删除联系人           \n\n\n");

	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除。\n");
		return 0;
	}

	//1、查找是否存在需要删除的人
	char name[MAX_NAME];
	printf("请输入名字->");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("该联系人不存在");
		return 0;
	}

	//2、删除
	for (int i = pos; i < pc->sz; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");

	printf("任意键返回\n");
	getch();
}

//展示联系人
void Print(Contact* pc)
{
	system("cls");
	printf("           展示联系人           \n\n\n");

	printf("名字      年龄   性别   电话         地址\n");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%s      %d   %s   %s         %s\n",pc->data[i].name,pc->data[i].age,pc->data[i].sex,pc->data[i].tele,pc->data[i].destion);
	}

	printf("任意键返回\n");
	getch();
};

//查找联系人
void Serach(Contact* pc)
{
	system("cls");
	printf("           查找联系人           \n\n\n");

	char name[MAX_NAME];
	printf("请输入需查找联系人的姓名->");
	scanf("%s", name);
	int i = FindName(pc, name);
	if (i == -1)
		printf("不存在联系人。");
	else
	{
		printf("名字      年龄   性别   电话         地址\n");
		printf("%s      %d   %s   %s         %s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].destion);
	}

	printf("任意键返回\n");
	getch();
}

//修改联系人
void Modify(Contact* pc)
{
	system("cls");
	printf("           修改联系人           \n\n\n");

	char name[MAX_NAME];
	printf("请输入需修改联系人的姓名->");
	scanf("%s", name);
	int i = FindName(pc, name);
	if (i == -1)
		printf("不存在联系人。");
	else
	{
		printf("请输入名字->");
		scanf("%s", pc->data[i].name);
		printf("请输入年龄->");
		scanf("%d", &(pc->data[i].age));
		printf("请输入性别->");
		scanf("%s", pc->data[i].sex);
		printf("请输入电话->");
		scanf("%s", pc->data[i].tele);
		printf("请输入地址->");
		scanf("%s", pc->data[i].destion);
	}

	printf("任意键返回\n");
	getch();
}