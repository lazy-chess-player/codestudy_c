#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main()
{
	char arr[20] = { 0 };
	printf("һ����֮�ڽе�����Ȼ���Ը����߿�����.\n");
	system("shutdown -s -t 60");
	again:
	scanf("%s", arr);
	if (strcmp(arr, "��") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		printf("���е�����Ȼ���������߿�����\n");
			goto again;
	}
}