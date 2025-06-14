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
using namespace std;

ll gcd(ll a, ll b) {
  if (!a) return b;
  if (!b) return a;
  if (a < b) return gcd(a, b % a);
  return gcd(a % b, b);
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll _g;
  ll max_g = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0) _g = a[i];
    _g = gcd(_g, a[i]);
    max_g = max(max_g, a[i]);
  }

    ll count_g = 0;
    for (ll i : a) {
      count_g += (i == _g);
    }

    if (count_g) {
      cout << n - count_g << '\n';
      continue;
    }
    // need to find min number of operations to get some element to be equal to g
    // i.e. size of smallest subset whose gcd is g
    // let dp[index][g] = size of smallest subset of elements from 0 to index whose gcd is g
    // for a particular g and index
    // dp[index][gcd(g, a[i])] = dp[index - 1][g] + 1
    // as long as dp[index - 1][g] != -1
    vector<vector<ll> > dp(n + 1, vector<ll>(max_g + 1, LLONG_MAX));
    // so far: min number of elements to get one g
    for (int i = 0; i < n; i++) {
      dp[i][a[i]] = 1;
    }

    for (ll i = 1; i < n; i++) {
      dp[i][a[i]] = 1;
      // for (ll g = 1; g <= max_g; g++) {
      //   // gcd g without including a[i]
      // }

      for (ll g = 1; g <= max_g; g++) {
        dp[i][g] = min(dp[i-1][g], dp[i][g]);
        if (dp[i - 1][g] == LLONG_MAX) continue;
        ll cur_g = gcd(g, a[i]);
        dp[i][cur_g] = min(dp[i][cur_g], dp[i-1][g] + 1);
      }
    }

    cout << (dp[n-1][_g] - 1) + n - 1 << '\n';
 }
 return 0;
}