#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++);
		{
			printf(" ");
		}
		for (int k = 0; k < n; k++);
		{
			printf("*");
		}
	}
	return 0;
}
//----*
//---***
//--*****
//-*******