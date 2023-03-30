#include<stdio.h>
#include<math.h>
int findComplement(int num)
{
	int E = 0;
	int ret = 0;
	while (num)
	{
		if (!(num & 1))
			ret += pow(2, E);
		num >>= 1;
		E++;
	}
	return ret;
}
int main()
{
	int num = 1;
	printf("%d", findComplement(num));
	return 0;
}