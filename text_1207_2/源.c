#include <string.h>
#include <ctype.h>
int secondHighest(char* s)
{
    int first = -1, second = -1;
    for (int i = 0; s[i]; i++)
    {
        if (isdigit(s[i]))
        {
            int num = s[i] - '0';
            if (num > first)
            {
                second = first;
                first = num;
            }
            else if (num < first && num > second)
            {
                second = num;
            }
        }
    }
    return second;
}