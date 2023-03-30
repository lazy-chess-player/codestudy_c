#include <string.h>
#include <stdio.h>
int romanToInt(char* s)
{
    int ret = 0;
    int the_roman_number = 0;
    int temp = 0;
    int string_length = 0;;
    for (string_length = strlen(s) - 1; string_length >= 0; string_length--)
    {
        switch (*(s + string_length))
        {
        case 'I': the_roman_number = 1;
            break;
        case 'V': the_roman_number = 5;
            break;
        case 'X': the_roman_number = 10;
            break;
        case 'L': the_roman_number = 50;
            break;
        case 'C': the_roman_number = 100;
            break;
        case 'D': the_roman_number = 500;
            break;
        case 'M': the_roman_number = 1000;
            break;
        default:
            printf("数字错误");
            break;
        }
        if (the_roman_number >= temp)
            ret += the_roman_number;
        else
            ret -= the_roman_number;
        temp = the_roman_number;
    }
    return ret;
}
void main()
{
    char* roman_nuber = "DML";
    int ret = romanToInt(roman_nuber);
    printf("%s的翻译结果是%d\n", roman_nuber,ret);
}