#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool isPerfectSquare(int num)
{
	int sqrt_num = sqrt(num);
	if (sqrt_num * sqrt_num == num)
		return 1;
	else
		return 0;
}
void main()
{
	int a = 1000;
	printf("%d\n", isPerfectSquare(a));
}