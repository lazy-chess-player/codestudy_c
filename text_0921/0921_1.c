#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0)
		strs[0] = "";
	for (int i = 0; strs[0][i] != '\0'; i++)
	{
		for (int j = 1; j < strsSize; j++)
		{
			if (strs[0][i] != strs[j][i])
			{
				strs[0][i] = '\0';
				return strs[0];
			}
		}
	}
	return strs[0];
}
void main()
{
	char arr[][10] = {"absd", "asw", "aaasa"};
	int length = strlen(arr);
	longestCommonPrefix(arr, 3);
	printf(" %s", arr[0]);
}