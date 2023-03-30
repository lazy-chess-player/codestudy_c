#include <stdio.h>
int arrangeCoins(int n)
{
	int ret = 0;
	int i = 1;
	while (n>0)
	{
		n -= i++;
		if (n >= 0)
			ret++;
	}
	return ret;
}
void main()
{
	int num = 230;
	printf("%d", arrangeCoins(num));
}