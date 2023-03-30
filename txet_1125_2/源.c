#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int* constructRectangle(int area, int* returnSize)
{
	*returnSize = 2;
	int width = sqrt(area);
	while (area % width)
	{
		width--;
	}
	int* ret = (int*)malloc(sizeof(int) * 2);
	ret[0] = area / width;
	ret[1] = width;
	return ret;
}
int main()
{
	int num = 24;
	int len = 0;
	int* p = &len;
	int* arr = constructRectangle(num, p);
	for (int i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}