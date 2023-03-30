#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void main()
{
	char password[6] = "123456";
	int i = 0;
	while(i < 3)
	{
		printf("请输入密码:");
		scanf("%s", &password);
		if (strcmp( password , "123456") ==0 )
		{
			printf("登入成功");
			break;
		}
		else
		{
			printf("登入失败");
			system("cls");
			i++;
		}
	}
	if (i == 3)
		printf("无法登入");
}