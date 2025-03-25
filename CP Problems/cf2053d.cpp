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

const static ll MOD = 998244353;

ll power_mod(ll a, ll n, ll p) {
  // return a ^ n mod p
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

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  vector<ll> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  ll prod = 1;
  vector<ll> sorted_a(a);
  vector<ll> sorted_b(b);
  sort(sorted_a.begin(), sorted_a.end());
  sort(sorted_b.begin(), sorted_b.end());
  map<ll, ll> a_to_largest_index;
  map<ll, ll> b_to_largest_index;
  for (int i = 0; i < n; i++) {
    prod *= min(sorted_a[i], sorted_b[i]);
    prod %= MOD;
    if (prod < 0) prod += MOD;
    a_to_largest_index[sorted_a[i]] = i;
    b_to_largest_index[sorted_b[i]] = i;
  }

  cout << prod << " ";
  while (q--) {
    ll op, idx;
    cin >> op >> idx;
    idx--;
    if (op == 1) {
      // increase a at index
      ll val = a[idx];
      a[idx]++;
      ll actual_idx = a_to_largest_index[val];
      sorted_a[actual_idx]++;
      if (actual_idx > 0 && sorted_a[actual_idx - 1] == (sorted_a[actual_idx] - 1)) {
        // prev element is largest now
        a_to_largest_index[sorted_a[actual_idx - 1]] = actual_idx - 1;
      } else {
        // no element of prev size
        a_to_largest_index.erase(sorted_a[actual_idx] - 1);
      }

      if (!a_to_largest_index.count(sorted_a[actual_idx])) a_to_largest_index[sorted_a[actual_idx]] = actual_idx;
      // update prod
      prod *= power_mod(min(sorted_a[actual_idx] - 1, sorted_b[actual_idx]), MOD - 2, MOD);
      prod %= MOD;
      if (prod < 0) prod += MOD;
      prod *= min(sorted_b[actual_idx], sorted_a[actual_idx]);
      prod %= MOD;
      if (prod < 0) prod += MOD;
    } else {
      // increase b at index
      // increase a at index
      ll val = b[idx];
      ll actual_idx = b_to_largest_index[val];
      sorted_b[actual_idx]++;
      b[idx]++;
      if (actual_idx > 0 && sorted_b[actual_idx - 1] == (sorted_b[actual_idx] - 1)) {
        // prev element is largest now
        b_to_largest_index[sorted_b[actual_idx - 1]] = actual_idx - 1;
      } else {
        // no element of prev size
        b_to_largest_index.erase(sorted_b[actual_idx] - 1);
      }

      if (b_to_largest_index.count(sorted_b[actual_idx]) == 0) b_to_largest_index[sorted_b[actual_idx]] = actual_idx;

      // update prod
      prod *= power_mod(min(sorted_b[actual_idx] - 1, sorted_a[actual_idx]), MOD - 2, MOD);
      prod %= MOD;
      if (prod < 0) prod += MOD;
      prod *= min(sorted_a[actual_idx], sorted_b[actual_idx]);
      prod %= MOD;
      if (prod < 0) prod += MOD;
    }

    cout << prod << " ";
  }

  cout << "\n";
 }
 return 0;
}