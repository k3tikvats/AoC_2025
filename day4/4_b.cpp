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
int calc(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt=0;
            if(grid[i][j]=='.') continue;
            for(int a=-1;a<=1;a++){
                for(int b=-1;b<=1;b++){
                    if(a==0 && b==0) continue;
                    int x=i+a;
                    int y=j+b;
                    string num="";
                    if(x>=0 && x<n && y>=0 && y<m){
                        if(grid[x][y]=='@'||grid[x][y]=='X'){
                            cnt++;
                        }
                        
                    }
                }

            }
            
            if(cnt<4){
                grid[i][j]='X';
                ans++;
            }
        }
        // cout<<ans<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt=0;
            if(grid[i][j]=='X') grid[i][j]='.';
            
        }
    }
    return ans;
}
void solve()
{
    // your code goes here

    
    vector<vector<char>> grid; 
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue; 
        grid.emplace_back(line.begin(), line.end());
    }

    long long res = 0;
    while (true) {
        int c = calc(grid);   
        if (c == 0) break;
        res += c;
    }
    cout<<res<<endl;
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