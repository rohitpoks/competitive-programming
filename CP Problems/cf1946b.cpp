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
ll powMod(ll a, ll b, ll m) {
 // a ^ b mod m
  if (b % 2 == 0) return (powMod(a, b/2, m) % m) * (powMod(a, b/2, m) % m);
  return (powMod(a, b/2, m) % m) * (powMod(a, b/2 + 1, m) % m);
}
int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  ll ans = a[0];
  for (int i = 1; i < n; i++) {
   ans = max(a[i], ans + a[i]);
  }
  cout << (ll) (10e9 + 7) % ans;
 }
 return 0;
}