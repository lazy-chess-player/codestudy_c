#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//��������
	int arr[5] = {0};
	//��������
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	//�Ƚϴ�С
	//�����һ������Ϊ���ֵ
	int max = arr[0];
	//ѭ���Ƚ�
	for (i = 1; i < 5; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//�������
	printf("max = % d\n", max);
	return 0;
}