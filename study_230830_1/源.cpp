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
	int y1,n,y2;
	cin >> y1 >> n;
	vector<int> years(n);
	for (int i = 0; i < n; i++)
	{
		cin >> years[i];
	}
	cin >> y2;
	int ans = y2 - y1 + 1;
	for (int i = 0; i < n; i++)
	{
		if (years[i] < y2)
			ans--;
	}
	cout << ans << endl;
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