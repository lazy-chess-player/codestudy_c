#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include<stdbool.h>
#include<string.h>

#define MAX 1000000

int a[MAX];

bool isPrme(int n)
{
	if (a[n])
		return false;
	else
		return true;
}
int main()
{
	int num = 0;
	memset(a, 0, sizeof(a));
	for (int i = 2; i < sqrt(MAX); i++)
	{
		if (a[i] == 0)
		{
			for (int j = i + i; j < MAX; j += i)
				a[j] = 1;
		}
	}
	while (scanf("%d", &num) != EOF)
	{
		if (isPrme(num) == 1)
			printf("%d是质数\n", num);
		else
			printf("%d不是质数\n", num);
	}
	return 0;
}