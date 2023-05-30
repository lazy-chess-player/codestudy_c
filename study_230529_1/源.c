#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1

int main()
{
    int numRows = 0;
    printf("«Î ‰»Î–– ˝£∫");
    scanf_s("%d",&numRows);
    int** triangle = (int**)malloc(numRows * sizeof(int*));

    for (int i = 0; i < numRows; i++)
    {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
    }

    for (int i = 0; i < numRows; i++)
    {
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
    return 0;
}
