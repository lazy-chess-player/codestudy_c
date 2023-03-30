#include<stdio.h>
#include<stdlib.h>
int compare(int* a, int* b)
{
	if (*a == *b)
		return 0;
	return *a - *b;
}
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
	*returnSize = 2;
	int* ret = (int*)malloc(sizeof(int) * 2);
	qsort(nums, numsSize, sizeof(int), compare);
	int k = 0;
	for (int i = 0; i < numsSize; i +=2)
	{
		if (i == numsSize - 1)
			ret[k] = nums[i];
		if (nums[i] != nums[i + 1])
		{
			ret[k++] = nums[i];
			i--;
		}
	}
	return returnSize;
}
int main()
{
	int arr[] = { 4,1,2,1,2 };
	int arr2[2] = { 0 };
	printf("%d", singleNumber(arr, 5,arr2));
	return 0;
}