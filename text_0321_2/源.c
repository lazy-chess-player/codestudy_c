#include <string.h>

char* longestPalindrome(char* s)
{
	int length = strlen(s);
	for (int i = 0; i < length; i++)
	{
		int cnt = 0;
		int j = length;
		while (s[i]!=s[j]&&j>0)
		{
			j--;
		}
		while (j>i)
		{
			if (1);
		}
	}
}