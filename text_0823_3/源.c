#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int frog(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return frog(n - 1) + 1 + frog(n - 2) + 1;
}
void main()
{
	int n = 0;
	scanf("%d", &n);
	int m = frog(n);
	printf("%d层台阶共有%d跳法",n, m);
}