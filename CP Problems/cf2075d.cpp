#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <cassert>

using ll = long long;
using uint = unsigned int;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  vector<vector<vector<unsigned long long int> > > dp(61, vector<vector<unsigned long long int> >(61, vector<unsigned long long int>(61, LLONG_MAX)));
  for (int i = 0; i < 61; i++) {
    dp[0][0][i] = 0;
  }

  for (int i = 0; i < 61; i++) {
    for (int j = 0; j < 61; j++) {
      unsigned long long int pow_2 = 2;
      for (int k = 1; k < 61; k++) {
        if (i - k >= 0 && dp[i - k][j][k-1] != LLONG_MAX)
          dp[i][j][k] = min(dp[i][j][k], pow_2 + dp[i - k][j][k - 1]);

        if (j - k >= 0 && dp[i][j - k][k-1] != LLONG_MAX)
          dp[i][j][k] = min(dp[i][j][k], pow_2 + dp[i][j-k][k-1]);

        dp[i][j][k] = min(dp[i][j][k], dp[i][j][k-1]);
        pow_2 *= 2;
      }
    }
  }

  while (t--) {
    ll n, m;
    cin >> n >> m;
    // if (n == 0 || m == 0)
    // find the largest common prefix 110, 10 -> 1
    ll largest_common_prefix = 0;
    ll i_num = 1;
    for (int i = 0; i <= 60; i++) {
      ll j_num = 1;
      for (int j = 0; j <= 60; j++) {
        if ((n / i_num) == (m / j_num)) {
          ll offset = 64;
          if (n != 0) offset = __builtin_clzll(n);
          largest_common_prefix = max(largest_common_prefix, (ll) 64 - (ll) i - offset);
        }
        j_num *= 2;
      }

      i_num *= 2;
    }

    ll x = largest_common_prefix;
    if (n != 0) x = 64 - __builtin_clzll(n) - largest_common_prefix;
    ll y = largest_common_prefix;
    if (m != 0) y = 64 - __builtin_clzll(m) - largest_common_prefix;
    unsigned long long int res = LLONG_MAX;
    if (m != 0 && n != 0) res = ((unsigned long long int) 1 << (64 - __builtin_clzll(n))) + ((unsigned long long int) 1 << (64 - __builtin_clzll(m) + 1));
    for (int i = 0; i <= 64 - __builtin_clzll(n) - x; i++) {
      res = min(res, dp[x+i][y+i][60]);
    }
    cout << res << '\n';
  }

 return 0;
}