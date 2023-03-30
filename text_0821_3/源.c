#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int i = 0, j = 0, k = 0;
	int all = nums1Size + nums2Size;
	double ret = 0;
	int nums3[14]={0};
	for (; j < all; j++)
	{
		for (; i < all; i++)
		{
			if (nums1[i] < nums2[j])
			{
				nums3[k] = nums1[i];
				k++;
			}
			else
			{
				nums3[k] = nums2[j];
				k++;
				break;
			}
		}
	}

	if (all % 2 == 0)
		ret = nums3[(all - 1) / 2] + nums3[all / 2];
	else
		ret = nums3[all / 2];
	return ret;
}
void main()
{
	int arr1[] = { 1,2,5,7,9,11,13 };
	int arr2[] = { 2,3,4,5,6,7,8 };
	int a = 7;
	int b = 7;
	int c = findMedianSortedArrays(arr1, a, arr2, b);
	printf("%d\n", c);
}