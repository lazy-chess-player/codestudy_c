#include <stdbool.h>
#include <stdio.h>
bool isUgly(int n)
{
    if (n == 1)
    {
        return true;
    }
    else if (n == 0)
    {
        return false;
    }
    else if (n % 3 == 0)
    {
        return isUgly(n / 3);
    }
    else if (n % 5 == 0)
    {
        return isUgly(n / 5);
    }
    else if (n % 2 == 0)
    {
        return isUgly(n / 2);
    }
    else 
    {
        return false;
    }
}
void main()
{
    if (isUgly(24))
        printf("ÊÇ");
    else
        printf("·ñ");
}