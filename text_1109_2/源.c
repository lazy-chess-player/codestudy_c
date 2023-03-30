#include <stdlib.h>
int compare(int* a, int* b)
{
	return *a - *b;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	int length = 0;
	qsort(nums1, nums1Size, sizeof(nums1[0]), compare);
	qsort(nums2, nums2Size, sizeof(nums2[0]), compare);
	for (int i = 0, j = 0; i < nums1Size && j < nums2Size; )
	{
		if (nums1[i] > nums2[j])
		{
			j++;
		}
		else if (nums1[i] < nums2[j])
		{
			nums1[i] = 1001;
			i++;
		}
		else
		{
			i++;
			j++;
			length++;
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
	int* arr3 = intersect(arr1, sizeof(arr1) / sizeof(int), arr2, sizeof(arr2) / sizeof(int), p);
	int a = 100;
}