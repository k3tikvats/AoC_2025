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
    vector<pair<long long,long long>> segs;
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            break;
        size_t dash = line.find('-');
        if (dash == string::npos) continue; 
        string left = line.substr(0, dash);
        string right = line.substr(dash + 1);
        int l= stoll(left);
        int r= stoll(right);
        if(l>r) swap(l,r);
        segs.emplace_back(l, r);
    }
    sort(segs.begin(), segs.end());
    vector<int> id;
    while (getline(cin, line))
    {
        id.push_back(stoll(line));
    }
    for (auto x : id)
    {
        bool found = false;
        for (auto p : segs)
        {
            if (x >= p.first && x <= p.second)
            {
                found = true;
                break;
            }
            if(p.first > x) break;
        }
        if (found)
        {
            ans++;
        }
    }
    cout << ans << endl;
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