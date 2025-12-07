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
class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i]=1;
        }
    }
    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
void solve()
{
    // your code goes here

    int ans = 0;
    vector<vector<int>> pts; 
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue; 
        stringstream ss(line);
        int x,y,z;
        char comma;
        
        // Reads: int -> char(,) -> int -> char(,) -> int
        if (ss >> x >> comma >> y >> comma >> z) {
            pts.push_back({x, y, z});
        }
    }
    vector<vector<int>> adj(pts.size(), vector<int>(pts.size(), 0)); 
    for(int i=0;i<pts.size();i++){
        for(int j=i+1;j<pts.size();j++){
            int x1=pts[i][0];
            int y1=pts[i][1];
            int z1=pts[i][2];
            int x2=pts[j][0];
            int y2=pts[j][1];
            int z2=pts[j][2];

            int dist=pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2) + pow(abs(z1 - z2), 2);
            adj[i][j]=dist;
            adj[j][i]=dist;
        }
    }
    vector<pair<int, pair<int, int>>> edges;
    for(int i=0;i<pts.size();i++){
        for(int j=i+1;j<pts.size();j++){
            edges.push_back({adj[i][j], {i, j}});
        }
    }
    sort(edges.begin(), edges.end());

    DisjointSet dsu(pts.size());
    for (int i = 0; i < 1000; i++) {
        int weight = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (dsu.findParent(u) != dsu.findParent(v)) {
            dsu.unionBySize(u, v);
        }
    }
    
    sort(dsu.size.begin(), dsu.size.end(), greater<int>());
    cout << dsu.size[0]*dsu.size[1]*dsu.size[2] << endl;
    
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