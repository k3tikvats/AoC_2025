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
    vector<vector<char>> grid; 
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue; 
        stringstream ss(line);
        vector<char> row;
        char tok;
        while (ss >> tok) {
            row.push_back(tok);
        }
        grid.push_back(row);
    }
    string s="";
    for(int i=0;i<grid[0].size();i++){
        s+="0";
    }
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]=='S'){
                s[j]='1';
            }
            else if(grid[i][j]=='^'&&s[j]=='1'){
                ans++;
                s[j]='0';
                if(j>0) s[j-1]='1';
                if(j<grid[i].size()-1) s[j+1]='1';
            }
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