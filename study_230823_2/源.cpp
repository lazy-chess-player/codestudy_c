#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			for (int k = 1; k <= 6; k++)
			{
				int n = 0, m = 0;
				if (i == 1 || i == 4)
				{
					n += i;
				}
				else
				{
					m += i;
				}
				if (j == 1 || j == 4)
				{
					n += j;
				}
				else
				{
					m += j;
				}
				if (k == 1 || k == 4)
				{
					n += k;
				}
				else
				{
					m += k;
				}

				if (n == a && m == b)
				{
					cout<<"Yes"<<endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;
	return 0;
}