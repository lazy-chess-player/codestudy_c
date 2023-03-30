#include <stdio.h>
#include <math.h>
#include <string.h>
int titleToNumber(char* columnTitle)
{
	int length = strlen(columnTitle) - 1;
	int num = 0;
	for (int i =0; length >= 0; length--,i++)
	{
		num += ( * (columnTitle + length)-64)* pow(26, i);
	}
	return num;
}
void main()
{
	char* str = "AA";
	int ret = titleToNumber(str);
	printf("%d\n", ret);
}