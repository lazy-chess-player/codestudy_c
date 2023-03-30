#include <stdio.h>
#include <stdlib.h>
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	int* ans = (int*)malloc(sizeof(int) * (nums1Size + 1));

    for (int i = 0; i < nums1Size; ++i)
    {
        int j = 0;
        while (j < nums2Size && nums2[j] != nums1[i])
        {
            ++j;
        }
        int k = j + 1;
        while (k < nums2Size && nums2[k] < nums2[j])
        {
            ++k;
        }
        ans[i] = k < nums2Size ? nums2[k] : -1;
    }
    return ans;
}
int main()
{
	int arr1[] = { 4,1,2 };
	int arr2[] = { 1,3,4,2 };
	int len = 0;
	int* p = &len;
	int* ret = nextGreaterElement(arr1, 3, arr2, 4, p);
	return 0;
}