#include <stdio.h>
int main()
{
	double a = 1;
	double b = 1;
	int n = 1;
	//输入数据
	while (abs((b*b)/(a*a) - 2) < 0.01)
		{
			b = b + 2 * a;
			a = b - a;
			n = n + 1;
		}
		if (abs((b*b)/(a*a) - 2) >= 0.01)
		{
			printf("结果为%d", n);
		}
		//输出
	return 0;
}