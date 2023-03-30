#include <stdio.h>
#include "test.h"
void main()
{
	int a = 0;
	int b = 0;
	scanf_s("%d %d", &a, &b);
	printf("%d和%d相加=%d\n", a, b, counter[0](a, b));
	printf("%d和%d相减=%d\n", a, b, counter[1](a, b));
	printf("%d和%d相乘=%d\n", a, b, counter[2](a, b));
	printf("%d和%d相除=%d\n", a, b, counter[3](a, b));
}