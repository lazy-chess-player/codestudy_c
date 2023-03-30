#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int compar(int* a, int* b)
{
	return *a - *b;
}
bool containsDuplicate(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), compar);
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i - 1] == nums[i])
			return 1;
	}
	return 0;
}
void main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,9 };
	if (containsDuplicate(arr, sizeof(arr) / sizeof(int)))
		printf("ÊÇ");
	else
		printf("·ñ");
}