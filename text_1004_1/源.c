#include <stdio.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {

}
void main()
{
	int arr[] = { 1,1,4,5,1,4 };
	int tmp[] = { 0 };
	int length = sizeof(arr) / sizeof(int);
	plusOne(arr, length, tmp);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", tmp[i]);
	}
}