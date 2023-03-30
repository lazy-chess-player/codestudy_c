#include <stdbool.h>
#include <string.h>
#include <stdio.h>
bool isSubsequence(char* s, char* t)
{
	int len_1 = strlen(s);
	int len_2 = strlen(t);
	if (!len_1)
		return 1;
	if (len_2 < len_1)
		return 0;
	int i = 0;
	for (int j = 0; i < len_1 && j < len_2;)
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			t[j] -= 32;
			j++;
		}
	}
	if (len_1 == i)
		return 1;
	else
		return 0;
}
void main()
{
	char str1[] = "aeb";
	char str2[] = "abcs";
	printf("%d", isSubsequence(str1, str2));
}