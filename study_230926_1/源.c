#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	printf("%d\n", max);
	return 0;
}