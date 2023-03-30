#include <stdio.h>
int climbStairs(int n)
{
	int a = 0;
	int b = 1;
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret = a + b;
		a = b;
		b = ret;
	}
	return ret;
}
void main()
{
	int ret = climbStairs(44);
	printf("%d\n", ret);
}