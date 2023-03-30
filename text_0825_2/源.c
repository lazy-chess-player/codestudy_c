#include <stdio.h>
double power(int x,int y)
{
	if (y > 0)
		return x * power(x, y - 1);
	else if (y == 0)
		return 1;
	else
		return 1.0 / power(x, -y);
}
void main()
{
	double a = power(2, -4);
	printf("%f\n", a);
}