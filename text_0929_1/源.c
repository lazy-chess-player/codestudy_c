#include <stdio.h>
int singleNumber(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; i++)
	{
		int k = 0;
		for (int j = 0; j < numsSize; j++)
		{
			if (nums[i] == nums[j])
				k++;
		}
		if (k != 2)
			return nums[i];
	}
}
void main()
{
	int arr[] = {1 };
	printf("%d\n", singleNumber(arr, sizeof(arr)/sizeof(int)));
}