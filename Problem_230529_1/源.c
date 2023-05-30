#include <stdio.h>

void printArray(int* arr, int size)
{
    int* ptr = arr;  // ָ��ָ���������Ԫ��

    // �������鲢��ӡԪ��
    while (ptr < arr + size)
    {
        printf("%d ", *ptr);
        ptr++;  // ָ�������ָ����һ��Ԫ��
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
