#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
bool repeatedSubstringPattern(char* s)
{
    int len = strlen(s);
    for (int i = 1; i * 2 <= len; i++)
    {
        if (len % i == 0)
        {
            int if_is = 1;
            for (int j = i; j < len; j++)
            {
                if (s[j] != s[j - i])
                {
                    if_is = 0;
                }
            }
            if (if_is)
                return 1;
        }
    }
    return 0;
}
void main()
{
    char str[] = "sdhsdhsdh";
    printf("%d", repeatedSubstringPattern(str));
}