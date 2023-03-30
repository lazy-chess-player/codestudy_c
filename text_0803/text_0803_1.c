#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//创建数组
	int arr[5] = {0};
	//输入数据
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	//比较大小
	//假设第一个整形为最大值
	int max = arr[0];
	//循环比较
	for (i = 1; i < 5; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//输出数据
	printf("max = % d\n", max);
	return 0;
}