#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void main()
{
	int v[] = { 1,2,3,4,5,6,7,8,9,10 };
	int x = 0, sz = sizeof(v) / sizeof(v[0]), left = 0, right = sz, mid = 0;
	scanf("%d", &x);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (x > v[mid])
			left = mid + 1;
		else if (x < v[mid])
			right = mid;
		else
		{
			printf("下标是：%d\n", mid);
			break;
		}
	}
	if (right < left)
		printf("数组中查无此数\n");

}