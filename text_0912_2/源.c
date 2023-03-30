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
    case 'Ò¼': the_chnese_number = 1;
        break;
    case '·¡': the_chnese_number = 2;
        break;
    case 'Èþ': the_chnese_number = 3;
        break;
    case 'ËÁ': the_chnese_number = 4;
        break;
    case 'Îé': the_chnese_number = 5;
        break;
    case 'Â½': the_chnese_number = 6;
        break;
    case 'Æâ': the_chnese_number = 7;
        break;
    case '°Æ': the_chnese_number = 8;
        break;
    case '¾Á': the_chnese_number = 9;
        break;
    case 'Ê°': wei = 10;
        break;
    case '°Û': wei = 100;
        break;
    case 'Ç§': wei = 1000;
        break;
    case 'Íò': wei = 10000;
        break;
    case 'ÒÚ': wei = 100000000;
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
    char roman_nuber[] = { '·¡','Ç§','¾Á','°Û','·¡','Ê°','Îé','\0' };
    int ret = romanToInt(roman_nuber);
    printf("·­Òë½á¹ûÊÇ%d\n", ret);
}