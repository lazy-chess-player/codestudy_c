#include <stdio.h>
#include <string.h>
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
int beautySum(char* s)
{
    int n = strlen(s);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count[26] = { 0 };
        for (int j = i; j < n; j++)
        {
            count[s[j] - 'a']++;
            int mx = 0;
            int mn = 0x3f3f3f3f;
            for (int k = 0; k < 26; k++)
            {
                if (count[k] > 0)
                {
                    mx = MAX(mx, count[k]);
                    mn = MIN(mn, count[k]);
                }
            }
            res += mx - mn;
        }
    }
    return res;
}
int main()
{
	char str[] = "pgljlqegfyqhs";
    printf("%d", beautySum(str));
	return 0;
}