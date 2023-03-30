#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;
	int ret = 0;
	for (int i = 0, j = 1; j < numsSize; j++)
	{
		if (nums[i] != nums[j])
		{
			nums[i + 1] = nums[j];
			i++;
		}
		else
			ret++;
	}
	return numsSize - ret;
}
void main()
{
	int arr[] = { 1,1,2,2,2,5,7,8,9 };
	int length = sizeof(arr)/sizeof(arr[1]);
	int a = removeDuplicates(arr, length);
	printf("%d\n", a);
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ",arr[i]);
	}
}