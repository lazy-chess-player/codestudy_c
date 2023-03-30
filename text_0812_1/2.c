#include <stdio.h>
void main()
{
	int i = 0;
	int a = 10;
	int res = 0;
	for (; i < 0; i++)
	{
		res += A(a);
		a--;
	}
	printf("%d\n", res);
}
int A(x)
{
	int y = 0;
	for (; x > 1; x--)
	{
		y = y * x;
	}
	return y;
}