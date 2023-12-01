#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> p;
typedef long long ll;

void solution() 
{
    int n; cin >> n;
    vector<p> arr(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i].second;
        arr[i].first = arr[i].second - i;
    }
    sort(arr.begin(), arr.end(), [](p a, p b) 
        {
            if (a.first > b.first)
                return true;
            else if (a.first == b.first)
                return a.second > b.second;
            else
                return false;
        }
    );
    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i].first == arr[i + 1].first && arr[i].second + arr[i + 1].second > 0)
        {
            sum += arr[i].second + arr[i + 1].second;
            i++;
        }
    }
    cout << sum << endl;
}

int main()
{
    int t; cin >> t;
    while (t--) 
    {
        solution();
    }

    return 0;
}