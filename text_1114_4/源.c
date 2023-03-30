#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char* addStrings(char* num1, char* num2)
{
    int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
    char* ans = (char*)malloc(sizeof(char) * (fmax(i, j) + 3));
    int len = 0;
    while (i >= 0 || j >= 0 || add != 0)
    {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        ans[len++] = '0' + result % 10;
        add = result / 10;
        i--, j--;
    }
    for (int i = 0; 2 * i < len; i++)
    {
        int t = ans[i];
        ans[i] = ans[len - i - 1], ans[len - i - 1] = t;
    }
    ans[len++] = 0;
    return ans;
}
void main()
{
    char num1[] = "1234";
    char num2[] = "23769";
    printf("%s", addStrings(num1, num2));
}