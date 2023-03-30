int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize)
{
    int ans = -1, tmp = 0;
    int min = 0;
    for (int i = 0; i < pointsSize; i++)
    {
        if (x == points[i][0] || y == points[i][1])
        {
            tmp = abs(x - points[i][0]) + abs(y - points[i][1]);
            if (min > tmp)
            {
                min = tmp;
                ans = i;
            }
        }
    }
    return ans;
}
int main()
{
    int x = 3;
    int y = 4;
    int points[][2] = { {1, 2} ,{3, 1},{2, 4},{2, 3},{4, 4} };
    int pointsSize = 5;
    int* pointsColSize = &points;
    nearestValidPoint(x, y, points, pointsSize, pointsColSize);
    return 0;
}