#include <stdio.h>
#include <stdlib.h>
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
	int len = 0;
	int* tmp = (int*)malloc(sizeof(int) * (numsSize + 1));
	int* ans = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		tmp[nums[i]] = 1;
	}
	for (int i = 1; i < numsSize + 1; i++)
	{
		if (tmp[i] != 1)
		{
			ans[len] = i;
			len++;
		}
	}
	*returnSize = len;
	return ans;
}
int main()
{
	int arr[] = { 1,1 };
	int len = 0;
	int* p = &len;
	int* ans = findDisappearedNumbers(arr, sizeof(arr)/sizeof(arr[0]), p);
	return 0;
}