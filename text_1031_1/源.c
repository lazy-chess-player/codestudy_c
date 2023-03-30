#include <stdio.h>
#include <stdint.h>
uint32_t reverseBits(uint32_t n)
{
	uint32_t ret = 0;
	for (uint32_t i = 0; i < 32 && n > 0; ++i)
	{
		ret |= (n & 1) << (31 - i);
		n >>= 1;
	}
	return ret;
}
void main()
{
	uint32_t num = 00000000000000000000000000100000;
	printf("%d\n",reverseBits(num));
}