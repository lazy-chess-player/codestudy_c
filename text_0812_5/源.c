#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void main()
{
	char password[6] = "123456";
	int i = 0;
	while(i < 3)
	{
		printf("����������:");
		scanf("%s", &password);
		if (strcmp( password , "123456") ==0 )
		{
			printf("����ɹ�");
			break;
		}
		else
		{
			printf("����ʧ��");
			system("cls");
			i++;
		}
	}
	if (i == 3)
		printf("�޷�����");
}