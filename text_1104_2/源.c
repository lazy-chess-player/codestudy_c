#include <math.h>
#include <stdio.h>
#include <stdbool.h>
bool isPowerOfTwo(int n)
{
	for (int i = 0; i < 32; i++)
	{
		if (pow(2, i) == n)
			return 1;
	}
	return 0;
}
void main()
{
	if (isPowerOfTwo(4))
		printf("ÊÇ");
	else
		printf("·ñ");
}