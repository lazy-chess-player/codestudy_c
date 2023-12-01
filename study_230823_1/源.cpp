#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<p> pdt(n);
	
	for (ll i = 0; i < n; i++)
	{
		cin >> pdt[i].first >> pdt[i].second;
	}
	sort(pdt.begin(), pdt.end());
	ll r = 0;
	for (auto pd : pdt)
	{
		ll u = pd.first * k;
		r += pd.second;
		if (u < r)
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

int main()
{/*
	ll t; cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;*/
	vector<string> vec;
	vec.emplace_back("cat");
	string* ptr = &vec[vec.size() - 1];
	vec.emplace_back("dog");

	cout << *ptr << endl;
	return 0;
}