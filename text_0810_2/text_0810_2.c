#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a;
	int i = 2;
	scanf("%d", &a);
	while(i<a)
	{
		if (a % i == 0)
		{
			printf("不是素数");
			return 0;
		}
		else
			i++;
	}
	printf("是素数");
	return 0;
}