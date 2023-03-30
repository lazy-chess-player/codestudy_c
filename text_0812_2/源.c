#include <stdio.h>
int A(int x)
{
	int y = 1;
	for (; x > 1; x--)
	{
		y = y * x;
	}
	return y;
}
void main()
{
	int i = 10;
	int a = 10;
	int res = 0;
	for (i=0; i <10 ; i++)
	{
		res =res + A(a);
		a--;
	}
	printf("%d\n", res);
}