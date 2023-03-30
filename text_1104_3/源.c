#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isAnagram(char* s, char* t)
{
	if (strlen(s) != strlen(t))
		return 0;
	int map[26] = { 0 };
	for (int i = 0; i < strlen(s); i++)
	{
		map[*(s + i) - 97]++;
		map[*(t + i) - 97]--;
	}
	for (int i = 0; i < 26; i++)
	{
		if (map[i] != 0)
			return 0;
	}
	return 1;
}
void main()
{
	char* a = "world";
	char* b = "rowdl";
	if (isAnagram(a,b))
		printf("ÊÇ");
	else
		printf("·ñ");
}