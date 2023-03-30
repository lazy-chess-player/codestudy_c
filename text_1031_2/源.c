#include <stdio.h>
#include <stdlib.h>
int compar(int* a, int* b)
{
	return *a - *b;
}
int majorityElement(int* nums, int numsSize)
{
	qsort(nums, numsSize, 4, compar);
	return nums[numsSize / 2];
}
void main()
{
	int arr[] = { 2,2,2,3,3,3,3,3,1 };
	int length = sizeof(arr) / sizeof(int);
	printf("%d\n",majorityElement(arr, length));
}