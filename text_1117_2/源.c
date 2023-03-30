#include <stdio.h>
#include <stdlib.h>
int* compare(int* a, int* b)
{
	return *a - *b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize)
{
	qsort(g, gSize, sizeof(int), compare);
	qsort(s, sSize, sizeof(int), compare);
    int ret = 0;
    for (int i = 0, j = 0; i < gSize && j < sSize; i++, j++)
    {
        while (j < sSize && g[i] > s[j])
        {
            j++;
        }
        if (j < sSize)
        {
            ret++;
        }
    }
    return ret;
}
void main()
{
    int arr1[] = { 1,2,4,6,3,2,9,8,2 };
    int arr2[] = { 1,2,4,7,3,4,11,7,2 };
    printf("%d", findContentChildren(arr1, 9, arr2, 9));
}