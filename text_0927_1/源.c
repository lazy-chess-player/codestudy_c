#include <stdio.h>
int mySqrt(int x) {
	int i = 0;
	if (x >= 2147395600)
		return 46340;
	while ((i*i)<=x)
	{
		i++;
	}
	return i-1;
}
void main()
{
	int a = mySqrt(8);
	printf("%d\n", a);
}