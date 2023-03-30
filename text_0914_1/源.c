#include <stdio.h>
int isValid(char* s)
{
    int ret = 0,s_1 = 0,s_2 = 0,s_3 = 0;
    int string_length = strlen(s);
    for (int i = 0; i < string_length; i++)
    {
        switch (*(s + i))
        {
        case '(':s_1++;break;
        case '[':s_2++;break;
        case '{':s_3++;break;
        case ')':s_1--;break;
        case ']':s_2--;break;
        case '}':s_3--;break;
        }
        if (s_1 < 0 || s_2 < 0 || s_3 < 0)
            return 0;
    }
    if (s_1 == 0 && s_2 == 0 && s_3 == 0)
        return 1;
    else
        return 0;
}
void main()
{
	 char* a = "([)()]";
	 int b =isValid(a);
	 printf("%d\n", b);
}