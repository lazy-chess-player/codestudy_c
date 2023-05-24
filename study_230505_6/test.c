#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int* num1, int* num2)
{
	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;
}

//冒泡排序
void BubbleSort(int* arr, int length)
{
	for (int i = length; i >0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[j - 1])
				swap(arr + j, arr + j - 1);
		}
	}
}

//选择排序
void SelectSort(int* arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		if (minIndex != i)
			swap(&arr[i], &arr[minIndex]);
	}
}

//插入排序
void InsertSort(int* arr, int length)
{
	for (int i = 1; i < length; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int arr[13] = { 1,2,3,5,6,23,3,56,2,4,67,22,45 };
	int len = sizeof(arr) / sizeof(int);
	print(arr, len);
	BubbleSort(arr, len);
	print(arr, len);
	return 0;
}