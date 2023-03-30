#pragma once
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

void print_int_arr(int* arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d ",arr[i]);
	}
}