#include <stdio.h>
int total_number_1(int n)
{
	int input = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((n >> i) & 1)
			input++;
	}
	return input;
}
void main()
{
	int a = 2048;
	int b = total_number_1(a);
	printf("%d", b);
}