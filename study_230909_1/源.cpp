#include<iostream>
#include<algorithm>
#include<unordered_map>

typedef long long ll;

using namespace std;

//void solve()
//{
//	int k; cin >> k;
//	k--;
//	ll num = 2;
//	ll ans = 1;
//	while (k)
//	{
//		if (k % 2 == 0)
//		{
//			num *= num;
//			num %= 998244353;
//			k /= 2;
//		}
//		else
//		{
//			ans *= num;
//			ans %= 998244353;
//			k--;
//		}
//	}
//	cout << ans << endl;
//}


void solve()
{
	int n; cin >> n;
	unordered_map<int, int> folders;
	int temp;
	for (int i = 1; i < n; i++)
	{
		cin >> temp;
		folders[temp]++;
	}
	ll p = 0;
	for (int i = 1; i <= n; i++)
	{
		if (folders[i])
			p++;
	}
	cout << n - 1 - p << endl;
	return;
}

int main()
{
		solve();
}