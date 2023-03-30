#include <stdio.h>
#include <math.h>
int ADD_FIVE_NUMBER(int a,int n)
{
	int num = 0;
	int ret = 0;
	for (; n > 0; n--)
	{
		num += pow(10, n - 1);
	}
	for (; num > 0; num /= 10)
	{
		ret += num * a;
	}
	return ret;
}
void main()
{
	int a = 5;
	int n = 9;
	printf("%d\n", ADD_FIVE_NUMBER(a,n));
}