#include <string.h>
#include <stdio.h>
int romanToInt(char* s) 
{
	int sl = strlen(s);
	int num_1 = 0;
	int num_2 = 0;
	int ret = 0;
	for (int i = sl; i >= 0; i--)
	{
		switch (*(s + i))
		{
		case'I':
			num_1 = 1;
			break;
		case'V':
			num_1 = 5;
			break;
		case'X':
			num_1 = 10;
			break;
		case'L':
			num_1 = 50;
			break;
		case'C':
			num_1 = 100;
			break;
		case'D':
			num_1 = 500;
			break;
		case'M':
			num_1 = 1000;
			break;
		}
		if (num_1 > num_2)
			num_2 = num_1;
		else
			num_2 = -num_1;
		ret += num_2;
	}
	return ret;
}
void main()
{
	char number = "VII\0";
	int a = romanToInt(&number);
	printf("%d\n", a);
}