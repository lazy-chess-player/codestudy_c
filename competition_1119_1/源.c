#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0, m = 0;
	printf("������n��m:");
	scanf("%d%d", &n, &m);
	int factor = m < n ? m : n;
	while (n % factor != 0 || m % factor != 0)
		factor--;
	printf("���Լ����%d\n", factor);
	printf("��С��������%d\n", m*n*factor);
	return 0;
}