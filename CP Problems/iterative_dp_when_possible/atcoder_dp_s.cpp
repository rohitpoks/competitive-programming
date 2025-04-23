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
#include <cassert>

using ll = long long;
using namespace std;

const static ll MOD = 1e9 + 7;

// digit DP usual idea: always have a tight/free state, this makes things much easier!

int main() {
 ios_base::sync_with_stdio(false);
 ll k;
 string s;
 cin >> s;
 cin >> k;
 // dp[index][cap][j] -> number of x's such that sum of digits in x is j mod k. if cap is true, then the max x can be is s[index:]. 
 // else, x can be any len(s) digit number
 // when cap is 0:
 // dp[index][0][j] -> sum of (dp[index + 1][0][j - i]) for all i from 0 to 9
 // think of i as the digit we place when constructing our x. we can place any digit from 0 to 9
 // since there is no cap

 // when cap is 1:
 // dp[index][1][j] -> sum of (dp[index + 1][0][j - i]) for all i from 0 to s[index] - '1'
 // dp[index][1][j] += dp[index + 1][1][j - i] when i == s[index]
 // intuition: when we build x, the max x can be is s[index:]. If we don't place s[index] at position
 // index of x, the suffix of x can be as big as we want. else, the suffix of x can be at most s[index + 1:]
 vector<vector<vector<ll> > > dp(s.size(), vector<vector<ll> >(2, vector<ll>(k, 0)));
 // base case:
 // dp[s.size() - 1][0/1][s.back() - '0'] = 1

 for (ll i = 0; i <= 9; i++) {
  if (i > s.back() - '0') break;
  dp[s.size() - 1][1][(i) % k]++;
 }

 for (ll i = 0; i <= 9; i++) {
  dp[s.size() - 1][0][i % k]++;
 }


 for (ll index = s.size() - 2; index >= 0; index--) {
  for (ll cap = 0; cap <= 1; cap++) {
    for (ll j = 0; j < k; j++) {
      for (ll i = 0; i <= 9; i++) {
        ll next = j - i;
        next %= k;
        if (next < 0) next += k;
        assert(index + 1 <= dp.size());
        assert(cap <= dp[0].size());
        assert(cap <= dp[0].size());
        assert(next <= dp[0][0].size());
        if (!cap) {
          dp[index][cap][j] += dp[index + 1][0][next];
          dp[index][cap][j] %= MOD;
          if (dp[index][cap][j] < 0) dp[index][cap][j] += MOD;
        } else {
          if (i == (s[index] - '0')) {
            dp[index][cap][j] += dp[index + 1][1][next];
            dp[index][cap][j] %= MOD;
            if (dp[index][cap][j] < 0) dp[index][cap][j] += MOD;
          } else if (i < (s[index] - '0')) {
            dp[index][cap][j] += dp[index + 1][0][next];
            dp[index][cap][j] %= MOD;
            if (dp[index][cap][j] < 0) dp[index][cap][j] += MOD;
          }
        }

        dp[index][cap][j] %= MOD;
      }
    }
  }
 }

 ll res = dp[0][1][0] - 1;
 res %= MOD;
 if (res < 0) res += MOD;
 cout << res << '\n';
 return 0;
}