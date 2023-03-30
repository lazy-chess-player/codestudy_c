#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void main()
{
	int n = 0, m = 0,min = 0 ,ret = 0,i = 0;
	scanf("%d%d", &n,&m);
	if (m > n)
		min = n;
	else if (n > m)
		min = m;
	else
		ret = m;
	for (i = min;i>0; i--)
	{
		if (m % i == 0 && n % i == 0)
		{
			ret = i;
			break;
		}
	}
	printf("最大公约数是%d\n", ret);
}