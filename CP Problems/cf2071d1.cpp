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

using ll = unsigned long long;
using namespace std;

ll compute(vector<ll>& a, ll idx, ll p) {
  // cout << "next, computing idx " << idx << endl;
  if (idx <= a.size() - 1) {
    return a[idx];
  }

  if (idx % 2) return compute(a, idx - 1, p);
  // idx is even
  // a_1, a_2, a3 = a1, a4 = a1-2, a5 = a1-2, a6 = a1-2-3, a7 = a1-2-3, a8 = p and a4
  // a1, a2, a3, a1-2, a1-2, a1-3, a1-3, a1-3 + a4
  int n = (a.size() - 1) / 2;
  if (((idx / 2) % 2)) return p;
  return p ^ compute(a, idx / 2, p);
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  ll n, l, r;
  cin >> n >> l >> r;
  vector<ll> a(2 * n + 1, 0);
  ll p = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    p ^= a[i];
  }

  ll x = 0;
  // prepare x for the n + 1st index
  for (int i = 1; i <= (n + 1) / 2; i++) {
    x ^= a[i];
  }

  for (int i = n + 1; i <= 2 * n; i++) {
    a[i] = x;
    // cout << "at i " << i << " x is " << x << endl;
    if (i % 2) {
      x ^= a[(i + 1) / 2];
    }
  }

  if (n % 2 == 0) p ^= a[n + 1];

  cout << compute(a, l, p) << '\n';
 }
 return 0;
}