#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	char tmp[20]={0};
	int	all = 0;
	while (1)
	{
		scanf("%s", &tmp);
		if ((strcmp(tmp,"m") == 0) || (strcmp(tmp, "M") == 0) || (strcmp(tmp, "F") == 0) || (strcmp(tmp, "f") == 0))
		{
			all++;
		}
		else
		{ 
			break;
		}
	}
	printf("%d", all);
	return 0;
}