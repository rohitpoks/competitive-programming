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
#include <cassert>

using ll = long long;
using namespace std;

ll MOD = 998244353;

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


void populate(vector<ll>& fact) {
  ll cur = 1;
  for (ll i = 1; i <= 5 * 1e5; i++) {
    cur *= i;
    cur %= MOD;
    fact[i] = cur;
  }
}

vector<vector<ll> > dp(vector<ll>& c, ll target) {
  vector<vector<ll> > memo(27, vector<ll>(target + 1, 0));
  for (int i = 0; i <= c.size(); i++) {
    // 1 way of using elements from i through n to make sum c[i]?
    memo[i][0] = 1;
  }

  for (int i = 25; i >= 0; i--) {
    for (int t = 1; t <= target; t++) {
      // want to make t using array indices i through 25
      memo[i][t] = memo[i + 1][t];
      if (c[i] > 0 && t - c[i] >= 0) memo[i][t] += memo[i + 1][t - c[i]];
      memo[i][t] %= MOD;
    }
  }

  return memo;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 vector<ll> fact(1e5 * 5 + 1, 1);
 populate(fact);
 while (t--) {
  ll total = 0;
  vector<ll> c(26);
  for (int i = 0; i <= 25; i++) {
    cin >> c[i];
    total += c[i];
  }

  ll target = total / 2;
  if (total % 2) target++;
  ll even = total - target;
  ll odd = target;
  // even ! * odd ! / fact(c[i])
  vector<vector<ll> > memo = dp(c, target);
  ll ans = memo[0][target] * fact[even];
  ans %= MOD;
  ans *= fact[odd];
  ans %= MOD;
  for (ll i : c) {
    if (i != 0) {

      ans *= inverse(fact[i], MOD);
      ans %= MOD;
    }
  }

  cout << ans << '\n';
 }
 
 return 0;
}