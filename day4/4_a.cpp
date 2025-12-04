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
        grid.emplace_back(line.begin(), line.end());
    }
    int n = grid.size();
    int m = grid[0].size();
    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt=0;
            if(grid[i][j]!='@') continue;
            for(int a=-1;a<=1;a++){
                for(int b=-1;b<=1;b++){
                    if(a==0 && b==0) continue;
                    int x=i+a;
                    int y=j+b;
                    string num="";
                    if(x>=0 && x<n && y>=0 && y<m){
                        if(grid[x][y]=='@'){
                            cnt++;
                        }
                        
                    }
                }

            }
            
            if(cnt<4)ans++;
        }
        cout<<ans<<endl;
    }
    return ans;
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