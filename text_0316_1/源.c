#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>
int main()
{
	char arr[10] = { 0 };
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror("fopen:");
	}
	fputs("abcdefgh", pf);
	fgets(arr, 7, pf);
	fputs(arr, stdin);
	fclose(pf);
	return 0;
}