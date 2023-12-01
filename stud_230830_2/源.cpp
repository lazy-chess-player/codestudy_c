#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

void solve()
{
	ll n;
	cin >> n;
	vector<p> stores(n);
	ll tran = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> stores[i].first >> stores[i].second;
		tran += stores[i].second;
	}
	sort(stores.begin(), stores.end());
	ll profit = 0;
	ll i = 0;
	ll buy = 0;
	while (i < n && buy + stores[i].second <= tran / 2)
	{
		profit -= stores[i].first * stores[i].second;
		buy += stores[i].second;
		i++;
	}
	if (tran % 2)
	{
		stores[i].second--;
	}
	ll r = buy + stores[i].second - tran / 2;
	profit += r * stores[i].first;
	profit -= (stores[i].second - r) * stores[i].first;
	i++;
	for (; i < n; i++)
	{
		profit += stores[i].first * stores[i].second;
	}
	cout << profit << endl;
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
