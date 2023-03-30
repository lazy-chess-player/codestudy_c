#include <stdio.h>
int addDigits(int num)
{
	int ret = 0;
	while (1)
	{
		while (num)
		{
			ret += num % 10;
			num /= 10;
		}
		if (ret < 10)
			break;
		else
		{
			num = ret;
			ret = 0;
		}
	}
	return ret;
}
void main()
{
	printf("%d", addDigits(12345));
}