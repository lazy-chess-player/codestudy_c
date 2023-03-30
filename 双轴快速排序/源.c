#include <stdio.h>
#include <stdlib.h>


//双轴快排
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int start, end, k, left, right;
    *returnSize = numsSize;
    start = 0;
    end = numsSize - 1;
    sort(nums, start, end);
    return nums;
}
void sort(int* nums, int start, int end)
{
    if (start > end) return;
    int left = start;
    int right = end;

    if (nums[start] == nums[end])
    {
        if (start == end) //这里当区间范围为1时要注意一下，我当时卡了好久，当时一个while死循环……
        {
            //
        }
        else
        {
            for (int i = start; i < end; i++)
            {
                if (nums[i] != nums[end])
                {
                    swap(&nums[i], &nums[start]);
                    break; //这里交换就应该跳出循环 
                }
            }
        }
    }
    if (nums[start] > nums[end])
    {
        swap(&nums[start], &nums[end]);
    }

    int privot1 = nums[start];
    int privot2 = nums[end];
    while (left + 1 <= end && nums[left + 1] < privot1)
    {
        left++;
    }
    while (right - 1 >= start && nums[right - 1] > privot2)
    {
        right--;
    } //两步优化，但是这道题并没有提高什么效率
    int k = left + 1;

    while (k < right)
    {
        if (nums[k] < privot1)
        {
            left++;
            swap(&nums[left], &nums[k]);
            k++;
        }
        else if (nums[k] <= privot2)
        {
            k++;
        }
        else
        {
            right--;
            /*
            由于一开始right就在end位置，不用再判断right是否要移动一下再交换，可能你看不懂我在说啥，但是我的确要在这里注释一下。 nums[right] = nums[end]
            */
            swap(&nums[right], &nums[k]);
        }
    }
    swap(&nums[left], &nums[start]);
    swap(&nums[right], &nums[end]);
    sort(nums, start, left - 1);
    sort(nums, left + 1, right - 1);
    sort(nums, right + 1, end);
    // return nums;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int main()
{
    int arr[] = { 5, 8, 4, 2, 1, 6, 3, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
