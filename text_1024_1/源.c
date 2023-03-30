#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
char* convertToTitle(int columnNumber)
{
	char* ret = malloc(sizeof(char) * 8);
	int i = 0;
	while (columnNumber > 0)
	{
		int a = (columnNumber - 1) % 26 + 1;
		ret[i] = a - 1 + 'A';
		i++;
		columnNumber = (columnNumber - a) / 26;
	}
	ret[i] = '\0';
	int right = i - 1;
	int left = right - 1;
	while (right > left)
	{
		char tmp = ret[right];
		ret[right] = ret[left];
		ret[left] = tmp;
		right--;
		left++;
	}
	return ret;
}
void main()
{
	int num = 701;
	char* str = convertToTitle(num);
	printf("%s\n", str);
}