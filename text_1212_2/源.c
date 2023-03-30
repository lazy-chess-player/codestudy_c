#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int minOperations(int* nums, int numsSize)
{
    int ret = 0;
    int count = nums[0] - 1;
    for (int  i = 0; i < numsSize; i++)
    {
        count = MAX(nums[i], count + 1);
        ret += count - nums[i];
    }
    return ret;
}

int main()
{
    int num[] = { 1,1,1,63,7,9,34 };
    printf("%d", minOperations(num, sizeof(num) / sizeof(int)));
    return 0;
}