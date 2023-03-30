#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maximalNetworkRank(int n, int** roads, int roadsSize, int* roadsColSize)
{
    bool** connect =(bool**)malloc(sizeof(bool*)*n);
    for (int i = 0; i < n; i++)
    {
       connect[i] = (bool*)malloc(sizeof(bool) * n);
    }
    int* degree =(int*)malloc(sizeof(int)*n);
    memset(connect, 0, sizeof(connect));
    memset(degree, 0, sizeof(degree));
    for (int i = 0; i < roadsSize; i++) {
        int x = roads[i][0], y = roads[i][1];
        connect[x][y] = true;
        connect[y][x] = true;
        degree[x]++;
        degree[y]++;
    }

    int maxRank = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rank = degree[i] + degree[j] - (connect[i][j] ? 1 : 0);
            maxRank = MAX(maxRank, rank);
        }
    }
    free(degree);
    free(connect);
    return maxRank;
}

int main() 
{
    int n = 4;
    int** roads = (int**)malloc(sizeof(int*) * 4);
    int a[2] = { 0, 1 };
    int b[2] = { 0, 3 };
    int c[2] = { 1, 2 };
    int d[2] = { 1, 3 };
    roads[0] = a;
    roads[1] = b;
    roads[2] = c;
    roads[3] = d;
    int roadsSize = 4;
    int roadsColSize[] = { 2, 2, 2, 2 };
    int result = maximalNetworkRank(n, roads, roadsSize, roadsColSize);
    printf("%d\n", result); // 4

    n = 5;
    int** roads2 = (int**)malloc(sizeof(int*) * 6);
    int e[2] = { 0, 1 };
    int f[2] = { 0, 3 };
    int g[2] = { 1, 2 };
    int h[2] = { 1, 3 };
    int i[2] = { 2, 3 };
    int j[2] = { 2, 4 };
    roads2[0] = e;
    roads2[1] = f;
    roads2[2] = g;
    roads2[3] = h;
    roads2[4] = i;
    roads2[5] = j;
    roadsSize = 6;
    int roadsColSize2[] = { 2, 2, 2, 2, 2, 2 };
    result = maximalNetworkRank(n, roads2, roadsSize, roadsColSize2);
    printf("%d\n", result); // 5

    n = 8;
    int** roads3 = (int**)malloc(sizeof(int*) * 6);
    int k[2] = { 0, 1 };
    int l[2] = { 1, 2 };
    int m[2] = { 2, 3 };
    int n2[2] = { 2, 4 };
    int o[2] = { 5, 6 };
    int p[2] = { 5, 7 };
    roads3[0] = k;
    roads3[1] = l;
    roads3[2] = m;
    roads3[3] = n2;
    roads3[4] = o;
    roads3[5] = p;
    roadsSize = 6;
    int roadsColSize3[] = { 2, 2, 2, 2, 2, 2 };
    result = maximalNetworkRank(n, roads3, roadsSize, roadsColSize3);
    printf("%d\n", result); // 5

    return 0;
}
