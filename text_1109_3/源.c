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
				printf("С��%dֻ\n����%dֻ\nĸ��%dֻ\n", 3 * i, k, j - k);
			}
		}
	}
}