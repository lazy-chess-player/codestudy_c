#include "my_ku.h"
void moveZeroes(int* nums, int numsSize)
{
	int left = 0;
	int right =numsSize;
	while (right < numsSize)
	{
		if (nums[right])
		{
			int input = nums[right];
			nums[right] = nums[left];
			nums[left] = input;
			left++;
		}
		right++;
	}
}
int main()
{
	int arr[] = { 0,0,0,0,3,2,4 };
	moveZeroes(arr, sizeof(arr) / sizeof(int));
	print_int_arr(arr, sizeof(arr) / sizeof(int));
}
