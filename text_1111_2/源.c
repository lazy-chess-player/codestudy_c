#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* toHex(int num)
{
	int n = num;
	int len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	char* ans = (char*)malloc(sizeof(char) * len);

}