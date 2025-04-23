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

// 4
// 1 2 2 1 2 3
// should just pass?

using ll = long long;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 int n;
 cin >> n;
 vector<ll> a(n);
 vector<vector<ll> > dp(n + 1, vector<ll>(n + 1, LLONG_MAX));
 vector<ll> psum(1, 0);
 ll cur_sum = 0;
 for (int i = 0; i < n; i++) {
  cin >> a[i];
  dp[i][i] = 0;
  cur_sum += a[i];
  psum.push_back(cur_sum);
 }

// dp[l][r] -> min cost of combining elements from l to r
// note: 
 for (int l = n - 1; l >= 0; l--) {
  for (int r = 0; r < n; r++) {
    if (l > r) {
      // dp[1][0] = 0
      dp[l][r] = 0;
      continue;
    }

    if (l == r) continue;

    if (r == l + 1) {
      dp[l][r] = a[l] + a[r];
      continue;
    }
    
    for (int k = l + 1; k <= r; k++) {
      // k is where we make the division
      // assume everything to the left of k is one side, and everything to the right (including k) is another side
      // combine k w. k + 1
      ll ans = 0;
      if (k - 1 >= 0)
        ans += dp[l][k - 1];
      
      if (k < a.size())
        ans += dp[k][r];
      
      if (l + 1 < psum.size() && k - 1 >= 0) ans += psum[k] - psum[l];
      if (r + 1 < psum.size() && k >= 0) ans += psum[r + 1] - psum[k];
      dp[l][r] = min(dp[l][r], ans);
    }
  }
 }

 cout << dp[0][n-1];
 return 0;
}