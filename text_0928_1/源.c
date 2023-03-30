#include <string.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
char* addBinary(char* a, char* b)
{
	int length = strlen(a) - 1;
	int num = 0;
	for (; length >= 0; length--)
	{
		if (a[length] == '1')
			num += pow(2, strlen(a) - length - 1);
	}
	length = strlen(b) - 1;
	for (; length >= 0; length--)
	{
		if (b[length] == '1')
			num += pow(2, strlen(b) - length - 1);
	}
	length = 0;
	for (; pow(2, length) <= num; length++);
	char* ret=(char*)malloc(length/4);
	ret[length] = '\0';
	for(int i = 1; i <= length; i++)
	{
		if (num % 2 == 1)
			ret[length - i] = '1';
		else
			ret[length - i] = '0';
		num /= 2;
	}
	return ret;
}
void main()
{
	char* str1 = "11";
	char* str2 = "1";
	char* str3 = addBinary(str1, str2);
	printf("%s\n",str3);
}