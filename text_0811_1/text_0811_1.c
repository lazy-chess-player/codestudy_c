#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bit(unsigned int value)
{
	unsigned int ret = 0;
	int tmp[32] = { 0 };
	int i = 0;
	//��value������ÿһλ��������tmp
	for (i = 0; i < 32; i++)
	{
		tmp[i] = value % 2;
		value >>= 1;
		if (value == 0)
			break;
	}
	//0������������Ǹ�������retÿ�����������һλ����tmp[i]���ʵ�ַ�ת
	for (i = 0; i < 31; i++)
	{
		ret = ret ^ tmp[i];
		ret <<= 1;
	}
	return ret;
}

int main(void)
{
	unsigned int n = 0;
	scanf("%d", &n);
	printf("%u\n", n);
	n = reverse_bit(n);
	printf("%u\n", n);

	system("pause");
	return 0;
}