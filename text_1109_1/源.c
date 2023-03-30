#include <stdlib.h>
int compare(int* a, int* b)
{
	return *a - *b;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	int length = 0;
	qsort(nums1, nums1Size, sizeof(nums1[0]), compare);
	qsort(nums2, nums2Size, sizeof(nums2[0]), compare);
	for (int i = 0; i < nums1Size; i++)
	{
		int if_same = 0;
		int j = 0;
		for (; j < nums2Size; j++)
		{
			if (nums1[i] == nums2[j])
			{
				if_same = 1;
				length++;
				break;
			}
		}
		if (if_same)
		{
			for (int k = 0; k < i; k++)
			{
				if (nums1[k] == nums2[j])
				{
					nums1[i] = 1001;
					length--;
				}
			}
		}
		else
		{
			nums1[i] = 1001;
		}
	}
	qsort(nums1, nums1Size, sizeof(nums1[0]), compare);
	*returnSize = length;
	return nums1;
}
void main()
{
	int arr1[] = { 1,2,2,1 };
	int arr2[] = { 2,2 };
	int length = 0;
	int* p = &length;
	int* arr3 = intersection(arr1, sizeof(arr1) / sizeof(int), arr2, sizeof(arr2) / sizeof(int), p);
	int a = 100;
}