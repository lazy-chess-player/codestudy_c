#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char exchange(char a)
{
    if (a == '}')
        return '{';
    if (a == ']')
        return '[';
    if (a == ')')
        return '(';
    return 0;
}
bool isValid(char* s)
{
    int n = strlen(s);
    if (n % 2 == 1)
    {
        return 0;
    }
    int* str = (int*)malloc(sizeof(int)*(n+1));
    int top = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = exchange(s[i]);
        if (ch)
        {
            if (top == 0 || str[top - 1] != ch)
            {
                return false;
            }
            top--;
        }
        else
        {
            str[top] = s[i];
            top++;
        }
    }
    return top == 0 ? 1 : 0;
}
int main()
{
    char str[] = "{({[()]})}";
    printf("%d", isValid(str));
    return 0;
}