#include <string.h>
#include <stdio.h>
int countSegments(char* s)
{
    int ret = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
            ret++;                                    
    }
    return ret;
}
void main()
{
	char str[] = "aihsfk wdad wda w";
	printf("%d", countSegments(str));
}