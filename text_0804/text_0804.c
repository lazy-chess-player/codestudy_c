#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a, abs_a;
	printf("����:");
	scanf("%d", &a);
	if (a >= 0) abs_a = a;
	else abs_a = -a;
	printf("%d�ľ���ֵ��%d", a, abs_a);
	return 0;
}