#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int Hanoi(int n)
{
	if (n == 1)
		return 1;
	else
		return Hanoi(n - 1) + 1 + Hanoi(n - 1);
}
void main()
{
	int n = 0;
	scanf("%d", &n);
	int m = Hanoi(n);
	printf("%d�㺺ŵ����Ҫ�Ĳ�����%d\n", n, m);
}