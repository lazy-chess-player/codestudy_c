#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[32] = { 0 };
	int i = 0;
	unsigned int x = 0;
	unsigned int y = 0;
	for (i = 0; i < 32; i++)
	{
		scanf("%d", &arr[i]);
	}
	i = 0;
	for (i = 0; i < 31; i++)
	{
		x = x + arr[i] * (2 ^ i);
	}
	y = ~x;
	printf("%d\n", y);
	return 0;
}