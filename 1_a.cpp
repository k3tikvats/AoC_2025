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

    int cnt = 50;
    int ans = 0;
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            continue;
        char drxn = line[0];
        int move = stoi(line.substr(1));
        if (drxn == 'L')
            cnt = ((cnt - move) % 100 + 100) % 100;
        else if (drxn == 'R')
            cnt = (cnt + move) % 100;

        if (cnt == 0)
            ans++;
    }

    cout << ans << endl;
}

signed main()
{
    fastio int t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}