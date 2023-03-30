#include <stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
	int i = 0;
		for(; i < numsSize; i++)
		{
			if (nums[i] >= target)
				return i;
		}
	return i;
}
void main()
{
	int arr[] = { 1,2,3,4,7,9,11 };
	int length = sizeof(arr) / sizeof(arr[1]);
	int a = searchInsert(arr, length, 7);
	printf("%d\n", a);
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}