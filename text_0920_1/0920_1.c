#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int least_common_multiple(int x, int y)
{
	int input= 0;
	if (x < y)
		input = x;
	else if (x > y)
		input = y;
	else
		return x;
	input--;
	while( x % input != 0 || y % input != 0)
		input--;
	return x * y / input;
}
void main()
{
	int a = 12;
	int b = 11;
	int ret = least_common_multiple(a, b);
	printf("%d\n",ret);
}