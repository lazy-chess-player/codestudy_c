#include <stdio.h>
#include <stdlib.h>


//˫�����
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
        if (start == end) //���ﵱ���䷶ΧΪ1ʱҪע��һ�£��ҵ�ʱ���˺þã���ʱһ��while��ѭ������
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
                    break; //���ｻ����Ӧ������ѭ�� 
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
    } //�����Ż�����������Ⲣû�����ʲôЧ��
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
            ����һ��ʼright����endλ�ã��������ж�right�Ƿ�Ҫ�ƶ�һ���ٽ����������㿴��������˵ɶ�������ҵ�ȷҪ������ע��һ�¡� nums[right] = nums[end]
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
