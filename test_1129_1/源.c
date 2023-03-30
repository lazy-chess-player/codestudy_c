#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n = 0;
	int* arr = (int*)malloc(sizeof(int) * n);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	int sum = 1;
	for (int j = 0; j < n-1; j++)
	{
		if (arr[j + 1] == arr[j])
		{
			sum++;
		}
		else
		{
			printf("%d %d\n", arr[j], sum);
			sum = 1;
		}
	}
	return 0;
}