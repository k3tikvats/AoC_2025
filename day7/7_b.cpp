#include <bits/stdc++.h>

using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define fl(i, n) for (int i = 0; i < n; i++)
#define int long long
#define ll long long
#define in(n)    \
    long long n; \
    cin >> n;
#define pb push_back
#define eb emplace_back
#define pp pop
unsigned long long M = 1000000007;

void solve()
{
    // your code goes here

    int ans = 0;
    vector<string> grid;
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            continue;

        grid.push_back(line);
    }
    int n = grid.size();
    int m = grid[0].size();

    vector<int> v(m, 0);
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 'S')
            {
                v[j] = 1;
            }
            else if (grid[i][j] == '^' && v[j] >= 1)
            {
                ans++;
                if (j > 0)v[j - 1]+=v[j];
                if (j < grid[i].size() - 1)v[j + 1]+=v[j];
                v[j] = 0;
            }
        }
    }
    cout << accumulate(v.begin(), v.end(), 0LL) << endl;
}

signed main()
{
    fastio int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}