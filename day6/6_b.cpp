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
static inline string rtrim_zeros_int(string s) {
    if (s.empty()) return s;
    size_t pos = s.find_last_not_of('0');
    if (pos == string::npos) return "0";     // all zeros -> "0"
    s.erase(pos + 1);
    return s;
}
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
    int maxisz=0;
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout<<grid[i][j]<<" ";
            maxisz=max(maxisz,(int)grid[i][j].size());
        }
        cout<<endl;
    }
    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<m;j++){
    //         while(grid[i][j].size()<maxisz){
    //             grid[i][j]="0"+grid[i][j];
    //         }
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // vector<vector<string>> new_g; 
    // for(int j=0;j<m;j++){
    //     vector<string> row;
    //     for(int k=0;k<maxisz;k++){
    //         string val="";
    //         for(int i=0;i<n-1;i++){
    //             if(grid[i][j].size()>k) val+=grid[i][j][k];
    //         }
    //         row.push_back(rtrim_zeros_int(val));
    //     }
    //     row.push_back(grid[n-1][j]);
    //     new_g.push_back(row);
    // }
    // int nr=new_g.size();
    // int nc=new_g[0].size();
    // for(int i=0;i<nr;i++){
    //     for(int j=0;j<nc;j++){
    //         cout<<new_g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // bool flag=0;
    // for(int i=0;i<nr;i++){
    //     int temp=1;
    //     if(new_g[i][nc-1]=="*") flag=1;
    //     else if(new_g[i][nc-1]=="+"){
    //         flag=0;
    //         temp=0;
    //     }
    //     for(int j=0;j<nc-1;j++){
    //         if(flag){
    //             temp*=(stoll(new_g[i][j])-0);
    //         }else{
    //             temp+=(stoll(new_g[i][j])-0);
    //         }
    //     }
    //     // cout<<temp<<" ";
    //     ans+=temp;
    // }
    // cout<<endl;
    // cout << ans << endl;
    vector<vector<string>> cols; 
    cols.reserve(m);
    for (int j = 0; j < m; j++) {
        vector<string> col;
        col.reserve(maxisz + 1);
        for (int k = 0; k < maxisz; k++) {
            string val;
            for (int i = 0; i < n - 1; i++) {
                if ((int)grid[i][j].size() > k) val += grid[i][j][k];
                else val += ' '; // preserve spacing so rtrim_zeros_int doesn't break structure
            }
            // remove spaces then trim trailing zeros
            val.erase(remove(val.begin(), val.end(), ' '), val.end());
            col.push_back(rtrim_zeros_int(val));
        }
        // operator is bottom token of the column
        col.push_back(grid[n - 1][j]);
        cols.push_back(col);
    }

    // Evaluate right-to-left
    for (int idx = (int)cols.size() - 1; idx >= 0; --idx) {
        const auto& col = cols[idx];
        int nc = (int)col.size();
        if (nc == 0) continue;

        bool multiply = (col.back() == "*");
        long long acc = multiply ? 1 : 0;

        for (int t = 0; t < nc - 1; ++t) {
            const string& s = col[t];
            if (s.empty()) continue; // skip empty
            long long v = 0;
            // safe parse: only digits
            bool ok = !s.empty();
            for (char c : s) { if (!isdigit((unsigned char)c)) { ok = false; break; } }
            if (!ok) continue;
            v = stoll(s);
            if (multiply) acc *= v;
            else acc += v;
        }
        ans += acc;
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