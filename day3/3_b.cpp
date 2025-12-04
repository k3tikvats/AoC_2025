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
int getIndex(string str) {
  int maxIndex = 0;
  for (int i = 1; i < str.size(); i++) {
    if (str.at(i) > str.at(maxIndex)) maxIndex = i;
  }
  return maxIndex;
}
void solve()
{
    // your code goes here

    string s;
    long long  sum = 0;
    vector<int> indices(12);
    while (getline(cin, s)) {
      long long  num = 0;
      int n = s.size();
      indices.at(0) = getIndex(s.substr(0, n - 11));
      for (int i = 1; i < 12; i++) {
        indices.at(i) = indices.at(i - 1) + getIndex(s.substr(indices.at(i - 1) + 1, n + i - 12 - indices.at(i - 1))) + 1;
      }
      for (int i = 0; i < 12; i++) {
        num += (s.at(indices.at(i)) - 48) * pow(10, 11 - i);
      }
      sum += num;
      // cout << num << endl;
    }
    cout << sum << endl;
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


