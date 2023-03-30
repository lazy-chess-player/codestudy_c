#include"contact.h"
//通讯录
//1、信息存储，储存1000个人的信息，包含名字，年龄，地址，性别，电话
//2、新建联系人，添加通讯录中的人员信息
//3、删除联系人
//4、修改联系人信息
//5、查找联系人



int main()
{
	//开辟空间
	Contact con;

	//初始化
	InitContact(&con);
	//主菜单选择界面
	int cmd_f = 0;
	do
	{
		menu();
		scanf("%d", &cmd_f);
		switch (cmd_f)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SERACH:
			Serach(&con);
			break;
		case MODIFY:
			Modify(&con);
			break;
		case PRINT:
			Print(&con);
			break;
		case EXIT:
			printf("退出");
			break;
		default:
			printf("无效指令，请重新输入->");
			break;
		};
	} while (cmd_f);
	return 0;
}
