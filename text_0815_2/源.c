#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main()
{
	char arr[20] = { 0 };
	printf("一分钟之内叫爹，不然电脑给你踹开线来.\n");
	system("shutdown -s -t 60");
	again:
	scanf("%s", arr);
	if (strcmp(arr, "爹") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		printf("快点叫爹，不然真给你电脑踹开线来\n");
			goto again;
	}
}