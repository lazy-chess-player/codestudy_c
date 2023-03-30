#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isHappy(int n)
{
    while (1)
    {
        if (n == 4)
            return false;
        if (n == 1)
            return true;
        int count = 0;
        while (n > 0)
        {
            int t = n % 10;
            count += t * t;
            n /= 10;
        }
        n = count;
    }
}
int main()
{
	char str[] = "pwwkew";
	printf("%d", isHappy(2));
	return 0;
}