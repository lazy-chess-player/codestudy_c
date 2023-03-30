#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void main()
{
	int a = 0;
	int b = 1;
	scanf("%d", &a);
	for (; a > 1; a--)
	{
		b = b * a;
	}
	printf("%d\n",b);
}