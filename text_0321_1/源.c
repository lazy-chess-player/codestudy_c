#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    if (nums1Size > nums2Size)
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int low = 0, high = nums1Size, half = (nums1Size + nums2Size + 1) / 2;
    while (low <= high) 
    {
        int i = (low + high) / 2;
        int j = half - i;
        if (i < nums1Size && nums2[j - 1] > nums1[i]) 
        {
            low = i + 1;
        }
        else if (i > 0 && nums1[i - 1] > nums2[j])
        {
            high = i - 1;
        }
        else {
            int max_left = 0;
            if (i == 0) 
            {
                max_left = nums2[j - 1];
            }
            else if (j == 0) 
            {
                max_left = nums1[i - 1];
            }
            else 
            {
                max_left = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
            }
            if ((nums1Size + nums2Size) % 2 == 1)
            {
                return max_left;
            }
            int min_right = 0;
            if (i == nums1Size)
            {
                min_right = nums2[j];
            }
            else if (j == nums2Size)
            {
                min_right = nums1[i];
            }
            else
            {
                min_right = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
            }
            return (max_left + min_right) / 2.0;
        }
    }
    return 0.0;
}

int main() 
{
    int nums1[] = { 1, 2 };
    int nums1Size = 2;
    int nums2[] = { 3, 4 };
    int nums2Size = 2;
    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("%.5f", median);
    return 0;
}
