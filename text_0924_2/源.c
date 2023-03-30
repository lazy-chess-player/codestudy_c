#include <stdio.h>
#include <string.h>
int lengthOfLastWord(char* s) {
	int i = strlen(s)-1;
	int ret = 0;
	while (1)
	{
		if (*(s + i) == ' ')
			i--;
		else
		{
			ret++;
			if (i == 0)
				break;
			i--;
			if (*(s + i) == ' ')
				break;
		}
	}
	return ret;
}
void main()
{
	char* str = "a ";
	int length = lengthOfLastWord(str);
	printf("%d\n", length);
}