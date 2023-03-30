#include <string.h>
#include <stdio.h>
int longestPalindrome(char* s)
{
	int map[52] = { 0 };
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] > 96)
			map[s[i] - 'a']++;
		else
			map[s[i] - 'A' + 26]++;
	}
	int if_singular = 0;
	int ret = 0;
	for (int j = 0; j < 52; j++)
	{
		if (map[j] % 2)
		{
			map[j]--;
			if_singular = 1;
		}
		ret += map[j];
	}
	return ret + if_singular;
}
void main()
 {
	char str[] = "AAaaabbc";
	printf("%d", longestPalindrome(str));
}