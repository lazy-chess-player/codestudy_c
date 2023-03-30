#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char* licenseKeyFormatting(char* s, int k)
{
	char* ret = (char*)malloc(sizeof(s));
	int len = strlen(s) - 1;
	int ret_len = 0;
	while (len)
	{
		if (s[len] != '-')
		{
			ret[ret_len++] = islower(s[len]) ? s[len] - 32 : s[len];
		}
		len--;
	}
	ret[ret_len] = 0;

}