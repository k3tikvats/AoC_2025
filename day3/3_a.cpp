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
    string line;
    while (getline(cin, line))
    {
        int maxi=INT_MIN;
        for(int i=0;i<line.size();i++){
            for(int j=i+1;j<line.size();j++){
                int num = stoi(string(1,line[i])+string(1,line[j]));
                maxi=max(maxi,num);
            }
        }
        ans += maxi;
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