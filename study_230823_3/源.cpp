#include <iostream>
#include <vector>
#include <queue>


using namespace std;

typedef long long ll;
typedef pair<int,int> p;


bool check(int v,vector<p> mem)
{
	priority_queue<int> fast;
	priority_queue<int> slow;

	for (auto temp : mem)
	{
		if (temp.first >= v)
			fast.push(temp.first + temp.second - v);
		else
		{
			slow.push(temp.second);
		}
	}
	if (fast.size() < slow.size())
		return false;
	while (!slow.empty())
	{
		if (fast.top() >= slow.top())
		{
			fast.pop();
			slow.pop();
		}
		else
			return false;
	}
	return true;
}

void solve()
{
	int n = 0;
	cin >> n;
	vector<p> mem(n);
	for (int i = 0; i < n; i++)
	{
		cin >> mem[i].first >> mem[i].second;
	}
	sort(mem.begin(), mem.end());
	int l = 0;
	int r = 1e9; 
	int v = 0;
	while (l < r)
	{
		v = (r + l + 1) / 2;
		if (check(v, mem))
		{
			l = v;
		}
		else
		{
			r = v - 1;
		}
	}
	cout << l << endl;
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