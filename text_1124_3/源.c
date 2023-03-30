#include<stdio.h>
#include<stdlib.h>
int compare(int* a, int* b)
{
	if (*a == *b)
		return 0;
	return *a - *b;
}
int singleNumber(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), compare);
	for (int i = 0; i < numsSize; i += 2)
	{
		if (i == numsSize - 1)
			return nums[i];
		if (nums[i] != nums[i + 1])
			return nums[i];
	}
	return nums[0];
}
int main()
{
	int arr[] = { 4,1,2,1,2 };
	printf("%d", singleNumber(arr, 5));
	return 0;
}