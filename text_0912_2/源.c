#include <string.h>
#include <stdio.h>
int romanToInt(char s[])
{
    int ret = 0;
    int the_chnese_number = 0;
    int wei = 0;
    int tmp = 0;
    int length = sizeof(s) / sizeof(s[0])-1;
    for (int i = 0; i < length; i++)
    {
    switch (s[i])
    {
        break;
    case 'Ҽ': the_chnese_number = 1;
        break;
    case '��': the_chnese_number = 2;
        break;
    case '��': the_chnese_number = 3;
        break;
    case '��': the_chnese_number = 4;
        break;
    case '��': the_chnese_number = 5;
        break;
    case '½': the_chnese_number = 6;
        break;
    case '��': the_chnese_number = 7;
        break;
    case '��': the_chnese_number = 8;
        break;
    case '��': the_chnese_number = 9;
        break;
    case 'ʰ': wei = 10;
        break;
    case '��': wei = 100;
        break;
    case 'ǧ': wei = 1000;
        break;
    case '��': wei = 10000;
        break;
    case '��': wei = 100000000;
        break;
    default:
        break;
    }
    if (wei != 0)
        ret += the_chnese_number * wei;
    wei = 0;
    }
    return ret;
}
void main()
{
    char roman_nuber[] = { '��','ǧ','��','��','��','ʰ','��','\0' };
    int ret = romanToInt(roman_nuber);
    printf("��������%d\n", ret);
}