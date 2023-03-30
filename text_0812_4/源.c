#include <stdio.h>
#include <string.h>
#include <Windows.h>
void main()
{
	char arr1[] = "hellow world";
	char arr2[] = "            ";
	int r = strlen(arr1) -1 , mid = r / 2, l = 0;
	while (l <=mid && r>mid)
	{
		arr2[l] = arr1[l];
		arr2[r] = arr1[r];
		Sleep(1000);
		system("cls");
		l ++ ;
		r -- ;
		printf("%s\n", arr2);
	}

}