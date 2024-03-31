#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <climits>

using ll = long long;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 int z;
 cin >> z;
 while (z--) {
  int n; int m;
  cin >> n >> m;
  vector<pair<int, int> > grid(n);
  for (int i = 0; i < n; i++) {
   cin >> grid[i].first;
  }
  for (int i = 0; i  < n; i++) {
   cin >> grid[i].second;
  }
  vector<pair<ll, ll> > dp(n);
  dp[n-1].first = grid[n-1].first;
  dp[n-1].second = grid[n-1].second;
  for (int i = n - 2; i >= 0; i--) {
   dp[i].first = grid[i].first + min(dp[i+1].second, dp[i+1].first);
   dp[i].second = grid[i].second + min(dp[i+1].first, dp[i+1].second);
  }
  ll res = LONG_LONG_MAX;
  for (int i = 0; i < m; i++) {
   res = min(res, dp[i].first);
  }
  cout << res << '\n';
 } 
 return 0;
}