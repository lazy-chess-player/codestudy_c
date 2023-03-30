#include <stdbool.h>
#include <stdio.h>
#include <math.h>
bool checkPowersOfThree(int n)
{
	for (int i = 14, num = 0; i >= 0; i--)
	{
		num = pow(3, i);
			if (num <= n)
				n -= num;
	}
	if (n == 0)
		return true;
	else
		return false;
}
int main()
{
	printf("%d", checkPowersOfThree(12));
	return 0;
}