#include <stdio.h>
int minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if (nums1Size * 6 < nums2Size || nums2Size * 6 < nums1Size)
        return -1;
    int sum1 = 0, sum2 = 0, i = 0, result = 0, diff = 0, step = 0;
    int hash_map1[7] = { 0 }, hash_map2[7] = { 0 };
    int* smaller = NULL, * larger = NULL;
    while (nums1Size > i)
    {
        sum1 += nums1[i];
        hash_map1[nums1[i]]++;
        i++;
    }
    i = 0;
    while (nums2Size > i)
    {
        sum2 += nums2[i];
        hash_map2[nums2[i]]++;
        i++;
    }
    if (sum1 == sum2)
    {
        return result;
    }
    else if (sum1 < sum2)
    {
        smaller = hash_map1;
        larger = hash_map2;
        diff = sum2 - sum1;
    }
    else
    {
        smaller = hash_map2;
        larger = hash_map1;
        diff = sum1 - sum2;
    }
    i = 1;
    while (0 < diff)
    {
        if (0 < smaller[i] + larger[7 - i])
        {
            step = (smaller[i] + larger[7 - i]) * (6 - i);
            if (step >= diff)
            {
                result += ((diff % (6 - i)) ? (diff / (6 - i) + 1) : diff / (6 - i));
            }
            else
            {
                result += (smaller[i] + larger[7 - i]);
            }
            diff -= step;
        }
        i++;
    }
    return result;
}
int main()
{
	int num1[] = { 1,2,3,4,5,6 };
	int num2[] = { 1,1,2,2,2,2 };
	printf("%d", minOperations(num1, sizeof(num1) / sizeof(int), num2, sizeof(num2) / sizeof(int)));
	return 0;
}