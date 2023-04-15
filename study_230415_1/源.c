#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>

int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	int temp = a;
	a > b ? temp = b, b = a, a = temp : 1;
	while (a % temp || b % temp)
	{
		temp--;
	}
	printf("%d", temp);
	return 0;
}
