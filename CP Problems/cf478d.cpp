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
 int R, G;
 cin >> R >> G;
 // height obtained by x blocks is best_h[x]
 vector<ll> best_h(4e5 + 10, 0);
 ll mod = 1e9 + 7;
 for (ll h = 1; h < 2e4; h++) {
  ll x = h * (h + 1) / 2;
  if (x > 4e5 + 5) break;
  best_h[x] = h;
 }

 for (int i = 1; i < 4e5 + 1; i++) {
  if (!best_h[i]) best_h[i] = best_h[i - 1];
 }

 // dp[r][level]: number of configurations if currently populating 'level' and use exactly r red blocks
vector<uint> prev(4e5 + 10);
 // 1 red block
 if (R > 0) prev[1] = 1;
 // 1 green block
if (G > 0) prev[0] = 1;
 for (int level = 2; level <= best_h[R + G]; level++) {
  vector<uint> dp(prev.size(), 0);
  for (int r = 0; r <= R; r++) {
    if (r - level >= 0) {
      dp[r] += prev[r - level];
      dp[r-level] %= mod;
    }

    int rem_green = G - (level * (level + 1) / 2 - r);
    if (rem_green >= 0) {
      dp[r] += prev[r];
      dp[r] %= mod;
    }
  }

  prev = dp;
 }

 ll res = 0;
 for (int i = 0; i <= R; i++) {
  res += prev[i];
  res %= mod;
 }

 cout << res << '\n';
 return 0;
}

// O(2 * 1e5 . 650)
// = O(2 * 6.5 * 1e7)
// = O(1.3 * 1e8), should barely pass