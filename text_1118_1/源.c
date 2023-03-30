#include <stdio.h>
#include <math.h>
int hammingDistance(int x, int y)
{
    int sum = x ^ y;
    int ret = 0;
    while (sum)
    {
        ret += sum & 1;
        sum >>= 1;
    }
    return ret;
}
void main()
{
	int a = 93;
	int b = 73;
	printf("%d", hammingDistance(a, b));
}