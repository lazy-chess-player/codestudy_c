#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;
const int maxm = 5005;

int main()
{
    vector<vector<double>> dp;
    int n, m;
    cin >> n >> m;
    int A = n + m - m * ceil((double)n / m);
    int B = m - A;
    dp.resize(A + 1);
    for (auto& elem : dp)
        elem.resize(B + 1);
    double p = ceil((double)n / (double)m) / n;
    double q = (ceil((double)n / (double)m) - 1) / n;
    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            if (i == 0 && j != 0)
                dp[i][j] = q * j / (p * i + q * j) * dp[i][j - 1] + 1 / (p * i + q * j);
            else if (i != 0 && j == 0)
                dp[i][j] = p * i / (p * i + q * j) * dp[i - 1][j] + 1 / (p * i + q * j);
            else if (i == 0 && j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = p * i / (p * i + q * j) * dp[i - 1][j] + q * j / (p * i + q * j) * dp[i][j - 1] +
                1 / (p * i + q * j);
        }
    }
    cout.precision(9);
    cout.setf(ios::fixed);
    cout << dp[A][B] << endl;
    return 0;
}
