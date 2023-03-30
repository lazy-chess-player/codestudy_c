#include <stdio.h>
#include <math.h>
void Narcissistic_number()
{
	for (int i = 1; i <100000; i++)
	{
		if (i < 10)
		{
			printf("%d ", i);
		}
		else if (i < 100 && i >= 10)
		{
			if (i == pow(i % 10, 2) + pow((i - i % 10)/10, 2))
				printf("%d ", i);
		}
		else if (i < 1000 && i >= 100)
		{
			if (i == pow(i % 10, 3) + pow((i % 100 - i % 10) / 10, 3) + pow((i - i % 100) / 100, 3))
				printf("%d ", i);
		}
		else if (i < 10000 && i >= 1000)
		{
			if (i == pow(i % 10, 4) + pow((i % 100 - i % 10) / 10, 4) + pow((i % 1000 - i % 100) / 100, 4) + pow((i - i % 1000) / 1000, 4))
				printf("%d ", i);
		}
		else if (i < 100000 && i >= 10000)
		{
			if (i == pow(i % 10, 5) + pow((i % 100 - i % 10)/10, 5) + pow((i % 1000 - i % 100)/100, 5) + pow((i%10000 - i % 1000)/1000, 5) + pow((i- i%10000)/10000, 5))
				printf("%d ", i);
		}
	}
}
void main()
{
	Narcissistic_number();
}