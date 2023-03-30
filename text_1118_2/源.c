#include <stdio.h>
int islandPerimeter(int** grid, int gridSize, int* colSize)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int col = *colSize;
    for (i = 0; i < gridSize; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (grid[i][j])
            {
                if (i == 0 || !grid[i - 1][j])
                    sum++;
                if (i == gridSize - 1 || !grid[i + 1][j])
                    sum++;
                if (j == 0 || !grid[i][j - 1])
                    sum++;
                if (j == col - 1 || !grid[i][j + 1])
                    sum++;
            }
        }
    }
    return sum;
}
void main()
{
    int map[4][4] = { 1,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0 };
    int m = 4;
    int* n = m;
    printf("%d", islandPerimeter(map, 4, n));
}