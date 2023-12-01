#include <iostream>
#include <algorithm>

#define int long long

using namespace std;
const int N = 2e6 + 10;
int n, m;

struct node 
{
    int a, b;
    bool operator<(const node& x) const 
    {
        return b - a > x.b - x.a;
    }
} p[N];
void solve() 
{
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++) 
    {
        cin >> p[i].a >> p[i].b;
        sum += p[i].a;
    }

    if (n == 1) 
    {
        cout << p[1].b << "\n";
        return;
    }


    sort(p + 1, p + 1 + n);
    int mx = 0, delta = 0;
    for (int i = 1; i <= m - n && i <= n && p[i].b - p[i].a > 0; i++) 
    {
        delta += p[i].b - p[i].a;
        mx = i;
    }
    if (mx != n - 1) 
    {
        cout << sum + delta << "\n";
    }
    else
    {
        int ans1 = sum + delta - (p[mx].b - p[mx].a);
        int ans2 = sum + delta + (p[n].b - p[n].a);
        cout << max(ans1, ans2) << "\n";
    }
}

signed main() 
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1; cin >> T;
    while (T--) 
    {
        solve();
    }
    return 0;
}
