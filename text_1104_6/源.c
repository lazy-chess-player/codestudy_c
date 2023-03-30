#include<stdlib.h>
#include<stdio.h>
int compar(int* a, int* b)
{
	return *a - *b;
}
int missingNumber(int* nums, int numsSize)
{
		qsort(nums, numsSize, sizeof(int), compar);
		int i = 0;
		for (; i < numsSize; i++)
		{
			if (nums[i] != i)
				return i;
		}
		return i;
}
void main()
{
	int arr[] = { 0,1 };
	printf("%d",missingNumber(arr, sizeof(arr) / sizeof(int)));
}