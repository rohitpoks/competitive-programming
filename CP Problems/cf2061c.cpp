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
  int t;
  cin >> t;
  const ll MOD = 998244353;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
      cin >> arr[i];
    }

    vector<ll> dp(n + 1);
    dp[0] = (arr[0] == 0);
    if (n >= 2) {
      if (arr[1] == 1) {
        dp[1] = 1;
      } else if (arr[1] == 0) {
        // arr[1] can only be speaking the truth here if arr[0] is lying
        dp[1] = (arr[0] == 0);
      }
    }
    for (ll i = 2; i < n; i++) {
      // if ith person is speaking the truth, must have one of two cases
      // i - 1st person is speaking the truth
      if (arr[i] == arr[i-1]) {
        dp[i] += dp[i-1];
      }

      // i - 1st person lying => i - 2nd person speaking the truth
      if (arr[i-2] + 1 == arr[i]) {
        dp[i] += dp[i - 2];
      }

      dp[i] %= MOD;
    }

    ll ans;
    if (n >= 2) {
      ans = (dp[n - 1] + dp[n - 2]) % MOD;
    } else {
      ans = (dp[0] + 1) % MOD;
    }

    cout << ans << '\n';
  }
  return 0;
}