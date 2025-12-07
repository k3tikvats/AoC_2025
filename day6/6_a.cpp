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
    vector<vector<string>> grid; 
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue; 
        stringstream ss(line);
        vector<string> row;
        string tok;
        while (ss >> tok) {
            row.push_back(tok);
        }
        grid.push_back(row);
    }
    // for(int i=0;i<grid.size();i++){
    //     for(int j=0;j<grid[i].size();j++){
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int n = grid.size();
    int m = grid[0].size();
    bool flag=0;
    for(int j=0;j<m;j++){
        int temp=1;
        if(grid[n-1][j]=="*") flag=1;
        else if(grid[n-1][j]=="+"){
            flag=0;
            temp=0;
        }
        for(int i=0;i<n-1;i++){
            if(flag){
                temp*=(stoll(grid[i][j]));
            }else{
                temp+=(stoll(grid[i][j]));
            }
        }
        // cout<<temp<<" ";
        ans+=temp;
    }
    cout<<endl;
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