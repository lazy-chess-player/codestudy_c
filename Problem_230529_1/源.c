#include <stdio.h>

void printArray(int* arr, int size)
{
    int* ptr = arr;  // 指针指向数组的首元素

    // 遍历数组并打印元素
    while (ptr < arr + size)
    {
        printf("%d ", *ptr);
        ptr++;  // 指针递增，指向下一个元素
    }

    printf("\n");
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);

    return 0;
}
