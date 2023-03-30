#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int ABS(int x)
{
	int y = 0;
	if (x >= 0) y=x;
	else y= -x;
	return y;
}
int main()
{
	int a = 1;
	int b = 1;
	int n = 1;
	while (ABS((a * a) / (b * b) - 2) < 0.01)
	{
		b = b + 2 * a;
		a = b - a;
		n = n + 1;
	}
	if (ABS((a * a) / (b * b) - 2) >= 0.01)
	{
		printf("½á¹ûÎª%d", n);
	}
	return 0;
}