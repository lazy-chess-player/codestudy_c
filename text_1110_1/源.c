#include <stdbool.h>
#include <string.h>
#include <stdio.h>
bool canConstruct(char* ransomNote, char* magazine)
{
	int str_len1 = strlen(ransomNote);
	int str_len2 = strlen(magazine);
	if (str_len1 > str_len2)
		return 0;
	for (int i = 0; i < str_len1; i++)
	{
		int if_not = 1;
		for (int j = 0; j < str_len2; j++)
		{
			if (ransomNote[i] == magazine[j])
			{
				if_not = 0;
				ransomNote[i] -= 32;
				magazine[j] -= 32;
				break;
			}
		}
		if (if_not)
			return 0;
	}
	return 1;
}
void main()
{
	char str1[] = "a";
	char str2[] = "b";
	printf("%d", canConstruct(str1, str2));
}