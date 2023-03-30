#include <stdio.h>
#include<math.h>
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int num = 0;
    for (int i = digitsSize - 1; i >= 0; i--)
    {

        if (digits[i] == 9)
        {
            digits[i] = 0;
            num++;
        }
        else
        {
            digits[i]++;
            break;
        }
    }
    *returnSize = digitsSize;
    if (num == digitsSize)
    {
        int* p = (int*)malloc(sizeof(int) * (++digitsSize));
        p[0] = 1;
        for (int i = 1; i < digitsSize; p[i++] = 0);
        *returnSize = digitsSize;
        return p;
    }
    else
    {
        return digits;
    }
}
void main()
{
	int a[] = { 1,2,3,4,9,9,9 };
    int b = 0;
    int* p = &b;
    int* c = plusOne(a, sizeof(a) / sizeof(int), p);
	for (int i = 0; i < *p; i++)
	{
		printf("%d", c[i]);
	}
}