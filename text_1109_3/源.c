#include <stdio.h>
void main()
{
	for (int i = 100 / 3; i > 0; i--)
	{
		int j = 100 - 3 * i;
		for (int k = 1; k <= j; k++)
		{
			if (k * 5 + i * 1 + (j - k) * 3 == 100)
			{
				printf("小鸡%d只\n公鸡%d只\n母鸡%d只\n", 3 * i, k, j - k);
			}
		}
	}
}