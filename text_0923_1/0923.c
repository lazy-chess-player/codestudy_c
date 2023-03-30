#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) {
	if (numsSize == 0)
		return 0;
	int ret = 0;
	for (int i = 0; i < numsSize;)
	{
		if (nums[i] == val)
		{
			for (int j = i; j < numsSize; j++)
			{
				if (j==numsSize-1)
				{
					nums[j] = val + 1;
					break;
				}
				nums[j] = nums[j + 1];
			}
			ret++;
		}
		else
			i ++ ;
	}
	return numsSize - ret;
}
void main()
{
	int arr[] = { 3,2,2,3 };
	int length = sizeof(arr) / sizeof(arr[1]);
	int a = removeElement(arr, length,3);
	printf("%d\n", a);
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}