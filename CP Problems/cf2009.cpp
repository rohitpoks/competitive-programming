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
 ll t;
 cin >> t;
 while (t--) {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  vector<ll> ps(1);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    ps.push_back(ps.back() + a[i]);
  }

  for (ll& k : a) {
    ps.push_back(ps.back() + k);
  }

  ps.push_back(ps.back());

  for (ll z = 0; z < q; z++) {
    ll ans = 0;
    ll l, r;
    cin >> l >> r;
    l--;
    r--;
    ll i = l / n;
    ll j = r / n;
    l %= n;
    r %= n;
    ans += (j - i - 1) * ps[n];
    ans += (ps[i + n] - ps[i + l]);
    ans += (ps[r + 1 + j] - ps[j]);
    cout << ans << '\n';
  }

 }

 return 0;
}