#include <stdio.h>
#include <string.h>
#include <math.h>
char* toHex(int num)
{
    char c[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
    char* ans = (char*)malloc(sizeof(char) * 9);
    for (int i = 7; i >= 0; --i)
    {
        ans[i] = c[num & 0xF];
        num = num >> 4;
    }
    ans[8] = '\0';
    while (ans[0] == '0' && *(ans + 1) != '\0')
    {
        ans = ans + 1;
    }
    return ans;
}
void main()
{
	printf("%s",toHex(324));
}