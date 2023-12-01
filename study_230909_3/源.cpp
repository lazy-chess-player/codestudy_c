#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

typedef long long ll;

using namespace std;

double dp[5005][5005] = { 0.0 };

void solve()
{
	int n, m;
	cin >> n >> m;
	int a = n + m - ceil((double)n / (double)m) * m;
	int b = m - a;
	double p = ceil((double)n / (double)m) / n;
	double q = (ceil((double)n / (double)m) - 1) / (double)n;
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <=b; j++)
        {
			if (i == 0 && j == 0)
				dp[i][j] = 0;
			else if (i == 0)
				dp[i][j] = dp[i][j - 1] + 1 / (p * i + q * j);
			else if (j == 0)
				dp[i][j] = dp[i - 1][j] + 1 / (p * i + q * j);
			else
				dp[i][j] = p * i / (p * i + q * j) * dp[i - 1][j] + q * j / (p * i + q * j) * dp[i][j - 1] + 1 / (p * i + q * j);
        }
    }
	printf("%.10lf", dp[a][b]);
}

int main()
{
	solve();
}