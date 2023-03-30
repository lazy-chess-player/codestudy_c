#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	long time = 0;
	scanf("%d", &time);
	int fre = time / 1440;
	int rem = time % 1440;
	int num1 = rem / 60;
	int num2 = rem % 60;
	while (1)
	{
		if (num1 < 1)
		{
			printf("%d", num2 / 12 + 1 + 39 * fre);
			break;
		}
		if (num1 < 2)
		{
			printf("%d", (num2 + 1) / 12 + 5 + 39 * fre);
			break;
		}
		if (num1 < 3)
		{
			printf("%d", (num2 + 2) / 12 + 10 + 39 * fre);
			break;
		}
		if (num1 < 4)
		{
			if (num2 >= 9)
				num2 -= 12;
			printf("%d", (num2 + 3) / 12 + 15 + 39 * fre);
			break;
		}
		if (num1 < 5)
		{
			if (num2 >= 8)
				num2 -= 12;
			printf("%d", (num2 + 4) / 12 + 19 + 39 * fre);
			break;
		}
		if (num1 < 6)
		{
			if (num2 >= 19)
				num2 -= 24;
			else
				num2 = 0;
			printf("%d", (num2 + 5) / 12 + 23 + 39 * fre);
			break;
		}
		if (num1 < 7)
		{
			if (num2 >= 18)
				num2 -= 24;
			else
				num2 = 0;
			printf("%d", (num2 + 6) / 12 + 26 + 39 * fre);
			break;
		}
		if (num1 < 8)
		{
			if (num2 >= 29)
				num2 -= 36;
			else
				num2 = 0;
			printf("%d", (num2 + 7) / 12 + 29 + 39 * fre);
			break;
		}
		if (num1 < 9)
		{
			if (num2 >= 28)
				num2 -= 36;
			else
				num2 = 0;
			printf("%d", (num2 + 8) / 12 + 31 + 39 * fre);
			break;
		}
		if (num1 < 10)
		{
			printf("%d", num2 >= 51 ? 1 : 0 + 33 + 39 * fre);
			break;
		}
		if (num1 < 12)
		{
			printf("%d", num2 >= 11 ? 1 : 0 + 34 + 39 * fre);
			break;
		}
		if (num1 < 13)
		{
			break;
			printf("%d", num2 >= 34 ? 1 : 0 + 35 + 39 * fre);
		}
		if (num1 < 14)
		{
			printf("%d", num2 >= 51 ? 1 : 0 + 36 +39 * fre);
			break;
		}
		if (num1 < 23)
		{
			printf("%d", num2 >= 22 ? 1 : 0 + 37 + 39 * fre);
			break;
		}
		if (num1 < 24)
		{
			printf("%d", num2 >= 45 ? 1 : 0 + 38 + 39 * fre);
			break;
		}
		break;
	}
	return 0;
}