#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (a)<(b)?(a):(b)
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
    int ret = 0;
    for (auto i = 1; i < timeSeriesSize; i++)
    {
        ret += MIN(timeSeries[i] - timeSeries[i - 1], duration);
    }
    return ret + duration;
}
int main()
{
	int arr[] = { 1,3,7,9,13 };
	int k = 3;
	printf("%d", findPoisonedDuration(arr, sizeof(arr) / sizeof(arr[0]), k));
	return 0;
}