#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
void exchange_number(int* a,int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void main()
{
	int a = 13;
	int b = -7;
	exchange_number(&a, &b);
	printf("A:%d B:%d\n", a, b);
}