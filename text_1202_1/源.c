#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* minOperations(char* boxes, int* returnSize)
{
	int len = strlen(boxes);
	*returnSize = len;
	int* ans = (int*)malloc(sizeof(int) * len);
	for(int i = 0; i < len; i++)
	{
		ans[i] = 0;
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (boxes[j] == '1')
			ans[i] += abs(j - i);
		}
	}
	return ans;
}
int main()
{
	char boxs[] = "001011";
	int n = 0;
	int* p = &n;
	int* ret = minOperations(boxs, p);
	return 0;
}