#include <stdio.h>
#include<string.h>
int minimumRecolors(char* blocks, int k)
{
    int length = strlen(blocks);
    int sum = 0;
    int i = 0;
    while (i<k)
    {
        sum += blocks[i] == 'W' ? 1 : 0;
        i++;
    }
    int ans = sum;
    while (i < length)
    {
        sum+= blocks[i] == 'W' ? 1 : 0;
        sum -= blocks[i - k] == 'W' ? 1 : 0;
        ans = sum < ans ? sum : ans;
        i++;
    }
    return ans;
}

int main()
{
    char blocks[] = "WBB";
    int k = 1;
    int res = minimumRecolors(blocks, k);
    printf("%d\n", res);  // 3

    char blocks2[] = "WBWBBBW";
    k = 2;
    res = minimumRecolors(blocks2, k);
    printf("%d\n", res);  // 0

    return 0;
}
