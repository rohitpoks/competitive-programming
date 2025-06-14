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
#include <iomanip>
#include <climits>
#include <cassert>

using ll = long long;
using namespace std;

ll power_mod(ll a, ll n, ll p) {
  ll res = 1;
  ll mult = a;
  while (n > 0) {
    if (n % 2) res *= mult;
    res %= p;
    n /= 2;
    mult *= mult;
    mult %= p;

    if (mult < 0) mult += p;
    if (res < 0) res += p;
  }

  return res;
}


ll inverse(ll a, ll p) {
  return power_mod(a, p - 2, p);
}


const ll MOD = 1e9 + 7;

ll dp(int idx, const string& s, bool carry) {
  bool cur = s[idx] - '0';
  if (idx == 0) {
    // return 1 for 10
    if (carry) return 1;
    // return 0 for 1
    return 0;
  }

  if (cur && carry) {
    // even, next carry is 1
    return 1 + dp(idx - 1, s, 1);
  } else if (cur || carry) {
    // odd
    ll t_i = inverse(2, MOD) % MOD;
    ll a = dp(idx - 1, s, 0) * t_i;
    a %= MOD;
    ll b = dp(idx - 1, s, 1) * t_i;
    b %= MOD;
    return (1 + (a + b) % MOD) % MOD;
    // return 1 + dp(idx - 1, s, 0) / 2 + dp(idx - 1, s, 1) / 2;
  } else {
    // even, next carry is 0
    return (1 + dp(idx - 1, s, 0)) % MOD;
  }
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  string s;
  cin >> n;
  cin >> s;
  cout << dp(s.size() - 1, s, 0) << '\n';
  // cout << (23 * inverse(2, MOD)) % MOD << '\n';
 }
 return 0;
}