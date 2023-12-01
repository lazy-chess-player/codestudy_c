#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        vector<vector<int>> temp;
        for (auto cou : temp)
        {
            if (cou[0] < cou[1])
            {
                temp.push_back(cou);
            }
        }
        sort(temp.begin(), temp.end(), [](vector<int> a, vector<int> b)
            {
                if (a[1] == b[1])
                    return a[0] > b[0];
                else
                    return a[1] > b[1];
            }
        );
        int times = 0;
        int cnt = 0;
        for (auto cou : temp)
        {
            if (times + cou[0] <= cou[1])
            {
                times += cou[0];
                cnt++;
            }
            else
                break;
        }
        return cnt;
    }
};

int main()
{
    class Solution s;
    int n; cin >> n;
    vector<vector<int>> courses(n);
    for (auto cou : courses)
    {
        cou.resize(2);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> courses[i][0] >> courses[i][1];
    }
    cout<<s.scheduleCourse(courses)<<endl;
    return 0;
}