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


// void ternary_search(int &l, int &r, vector<int> &f, bool is_convex = true) {
//   while (r - l  > 2) {
//     int m1 = (2 * l + r) / 3;
//   // 2 * 0 + 9/3 => m1 = 3
//   // 0 + 2 * 9 / 3m2 -> 6
//     int m2 = (l + 2 * r) / 3;
//     if (f[m1] < f[m2]) {
//     // min exists on left 2 thirds
//       if (is_convex) r = m2;
//       else l = m1;
//     } else if (f[m2] < f[m1]) {
//       // min exists on right 2 thirds
//       if (is_convex) l = m1;
//       else r = m2;
//     } else {
//       // min exists in middle 1 / 3rd
//       r = m2;
//       l = m1;
//     }
//   }
// }

ll score(ll x, ll k, vector<ll>& psum_l1, vector<ll>& psum_l2) {
  return psum_l1[x] + psum_l2[k - x];
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  ll m;
  ll n;
  cin >> m >> n;
  vector<ll> l1;
  vector<ll> l2;
  for (ll i = 0; i < m + n; i++) {
    ll x;
    cin >> x;
    if (i < m) {
      l1.push_back(x);
    } else {
      l2.push_back(x);
    }
  }

  // assume m <= n
  if (m > n) {
    ll t = m;
    m = n;
    n = t;
    vector<ll> temp = l1;
    l1 = l2;
    l2 = temp;
  }

  sort(l1.begin(), l1.end());
  sort(l2.begin(), l2.end());
  vector<ll> psum_l1;
  vector<ll> psum_l2;
  psum_l1.push_back(0);
  psum_l2.push_back(0);
  ll l = 0;
  ll r = m - 1;
  while (l < r) {
    psum_l1.push_back(psum_l1.back());
    psum_l1.back() += (l1[r] - l1[l]);
    l++;
    r--;
  }

  l = 0;
  r = n - 1;
  while (l < r) {
    psum_l2.push_back(psum_l2.back());
    psum_l2.back() += (l2[r] - l2[l]);
    l++;
    r--;
  }

  ll k_max = min(m, (m + n) / 3);
  cout << k_max << '\n';
  for (ll k = 1; k <= k_max; k++) {
    // find best (x, k - x) pair which maximizes g(p, q)
    // x -> number of triangles in l1
    // k - x -> number of triangles in l2
    ll l = k * 2 - n;
    if (l < 0) l = 0;
    ll low = l;
    ll r = m - k;
    if (r > k) r = k;
    ll high = r;
    // cout << "for k = " << k << ", min number of triangles on line one is " << l << " and max number of triangles is " << r << endl;
    bool is_convex = false;
    // find the best x
    while (r - l  > 2) {
      ll m1 = (2 * l + r) / 3;
      ll m2 = (l + 2 * r) / 3;
      // g(m1) < g(m2) -> max exists on right third so search [m1, r]
      if (score(m1, k, psum_l1, psum_l2) < score(m2, k, psum_l1, psum_l2)) {
      // min exists on left 2 thirds
        if (is_convex) r = m2;
        else l = m1;
      } else if (score(m2, k, psum_l1, psum_l2) < score(m1, k, psum_l1, psum_l2)) {
        // g[m2] > g[m1] -> max exists on right 
        // min exists on right 2 thirds
        if (is_convex) l = m1;
        else r = m2;
      } else {
        // min exists in middle 1 / 3rd
        r = m2;
        l = m1;
      }
    }

    ll res = 0;
    // cout << "for k = " << k << endl;
    for (ll a = l; a <= r; a++) {
      if (a < low || a > high) continue;
      res = max(res, score(a, k, psum_l1, psum_l2));
      // cout << "checking a = " << a << endl << ", score is " << score(a, k, psum_l1, psum_l2) << endl;
    }

    cout << res << ' ';
  }
  cout << '\n';
 }
 return 0;
}