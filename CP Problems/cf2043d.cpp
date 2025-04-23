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
  ll l, r, g;
  cin >> l >> r >> g;

  if (r < g) {
    cout << -1 << ' ' << -1 << endl;
    continue;
  }

  ll smallest_div = (l / g) * g;
  if (l % g) smallest_div += g;
 
  ll largest_div = (r / g) * g;

  // when does an answer always exist?
  // squeeze range
  l = smallest_div / g;
  r = largest_div / g;
  ll range = r - l;
  // eg: range: 2-5 -> 3 
  bool done = false;
  for (ll i = range; i >= 0; i--) {
    // greedily pick largest range first
    for (ll _l = l; _l + i <= r; _l++) {
      ll _r = _l + i;
      // cout << "checking " << _l << "," << _r << endl;
      if (gcd(_l, _r) == 1) {
        cout << g * _l << ' ' << g * _r << '\n';
        done = true;
      }

      if (done) break;
    }

    if (done) break;
  }

  if (done) continue;
  cout << -1 << ' ' << -1 << '\n';
 }
 return 0;
}