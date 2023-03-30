#include <stdio.h>
#include <string.h>
int isPalindrome(char* s) 
{
    int right = strlen(s) - 1;
    if (right == 0)
    {
        return 1;
    }
    int left = 0;
    while (right > left)
    {
        if (s[left] < 48 || (s[left] < 65 && s[left]>57) || (s[left] < 97 && s[left]>90) || s[left]>122)
        {
            left++;
            continue;
        }
        if (s[right] < 48 || (s[right] < 65 && s[right]>57) || (s[right] < 97 && s[right]>90) || s[right]>122)
        {
            right--;
            continue;
        }
        if (s[left] < 91)
            s[left] += 32;
        if (s[right] < 91)
            s[right] += 32;
        if (s[left] != s[right])
            return 0;
        left++;
        right--;
    }
    return 1;
}
void main()
{
    char str[] = "A man, a plan, a canal: Panama";
    int a = isPalindrome(str);
    printf("%d\n", a);
}