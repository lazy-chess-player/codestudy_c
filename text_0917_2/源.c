#include <stdio.h>
int if_pow_2(int n,int* m)
{
	int input = 0;
	int a = n;
	for (int i = 0; i < 32; i++)
	{
		if ((n >> i) & 1)
			input++;
	}
	if (input > 1)
		return 0;
	else
	{
		while (a > 1)
		{
			(*m)++;
			a /= 2;
		}
		return 1;
	}
}
void main()
{
	int num = 1073741824;
	int pow_num = 0;
	if (if_pow_2(num,&pow_num))
		printf("%d是2的%d次方\n",num,pow_num);
	else
		printf("%d不是2的n次方\n", num);
}