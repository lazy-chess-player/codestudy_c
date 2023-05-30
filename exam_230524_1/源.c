#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 1

int main()
{
	int a = 0;
	int b = 0;
	while (scanf_s("%d %d",&a,&b)!=eof)
	{
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		int map_size = 100;
		int cnt = 0;
		int map[32] = { 0 };
		for (int i = 2; i <= a; i++)
		{
			if (!(a % i) && !(b % i))
			{
				map[cnt++] = i;
				a /= i;
				b /= i;
				i = 1;
			}
		}
		long long ans = (long long)a * (long long)b;
		while (cnt)
		{
			ans *= map[--cnt];
		}
		printf("%lld", ans);
	}
}
//
//int main()
//{
//	char str[100] = { '\0' };
//	scanf_s("%s", str);
//	int n = strlen(str);
//	while (n--)
//	{
//		if (str[n] == ' ')
//		{
//			for (int i = n; str[i] != ' ' && str[i] != '\0'; i++)
//			{
//				printf("%c",str[i]);
//			}
//			if (n)
//				printf("%c", ' ');
//		}
//	}
//	return 0;
//}