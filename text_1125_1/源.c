#include<stdio.h>
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
	if (nums[0] && numsSize == 1)
		return 1;
	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		int tmp = 0;
		while (nums[i])
		{
			tmp++;
			i++;
			if (i == numsSize)
				break;
		}
		if (tmp > ret)
		{
			ret = tmp;
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1,0,1,1,1,0,1,1,0,1,1,1,1 };
	printf("%d", findMaxConsecutiveOnes(arr, sizeof(arr) / sizeof(int)));
}