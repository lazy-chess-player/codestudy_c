#include <stdio.h>
#include <stdlib.h>
int compare(int* a, int* b)
{
	if (*b > *a)
		return 1;
	else if (*b < *a)
		return -1;
	else
		return 0;
}
int thirdMax(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), compare);
	int input = 0;
	for (int i = 0; i < numsSize - 1; i++)
	{
		if (nums[i] != nums[i + 1])
			input++;
		if (input == 2)
			return nums[i + 1];
	}
	return nums[0];
}
void main()
{
	int arr[] = {1,2,4,3,4,6,3,3,5,5,5};
	printf("%d",thirdMax(arr, sizeof(arr) / sizeof(arr[0])));
}