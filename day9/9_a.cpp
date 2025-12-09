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
    vector<vector<int>> pts; 
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue; 
        stringstream ss(line);
        int x,y;
        char comma;
        
        // Reads: int -> char(,) -> int
        if (ss >> x >> comma >> y) {
            pts.push_back({x, y});
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<pts.size();i++){
        for(int j=i+1;j<pts.size();j++){
            int len=abs(pts[i][0]-pts[j][0])+1;
            int breadth=abs(pts[i][1]-pts[j][1])+1;
            maxi=max(maxi,len*breadth);
        }
    }
    cout<<maxi<<endl;
    
    
    
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