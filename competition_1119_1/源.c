#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0, m = 0;
	printf("请输入n和m:");
	scanf("%d%d", &n, &m);
	int factor = m < n ? m : n;
	while (n % factor != 0 || m % factor != 0)
		factor--;
	printf("最大公约数：%d\n", factor);
	printf("最小公倍数：%d\n", m*n*factor);
	return 0;
}