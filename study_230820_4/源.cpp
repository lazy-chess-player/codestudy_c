#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;


bool check(p point,vector<p> forbid)
{
	for (int i = 0; i < forbid.size(); i++)
	{
		if ((point.first > forbid[i].first && point.second < forbid[i].second)|| (point.first < forbid[i].first && point.second > forbid[i].second))
			return false;
	}
	return true;
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	ll num = n * m;
	vector<p> gird(num);;
	ll temp = 0;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
		{
			cin >> temp;
            gird[temp] = { i,j };
		}
	}
    if (n == 1 || m == 1) 
    {
        cout << n * m <<endl;
        return;
    }
	vector<p> forbid;
	for (ll i = 0; i < n + m - 1; i++)
	{
		if(check(gird[i], forbid))
			forbid.emplace_back(gird[i]);
		else
		{
			cout << i << endl;
			return;
		}
	}
	
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
