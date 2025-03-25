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
bool is_prime(ll x) {
  for (ll i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }

  return true;
}

bool is_semi_prime(ll x, ll &a, ll &b) {
  if (x == ((ll) sqrt(x) * (ll) sqrt(x))) {
    a = sqrt(x);
    b = a;

    // cout << "returning true (1) for " << x << endl;
    return is_prime(a);
  }

  ll res = 0;
  ll u = sqrt(x);
  ll original_x = x;
  for (ll i = 2; i <= u; i++) {
    while (x % i == 0) {
      a = i;
      b = x / i;
      res += 2;
      x /= i;
    }
  }

  return res == 2;
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }

  map<ll, ll> count;
  for (ll i : arr) count[i]++;

  int total_prime_count = 0;
  for (ll i : arr) {
    if (is_prime(i)) total_prime_count++;
  }

  // cout << "total_prime_count is " << total_prime_count << endl;
  ll res = 0;
  for (ll i : arr) {
    if (is_prime(i)) {
      res += (total_prime_count - count[i]);
    }
  }
  res /= 2;
  // cout << "res so far is " << res << endl;
  for (auto i : count) {
    ll a = 0, b = 0;
    if (is_semi_prime(i.first, a, b)) {
      ll x = count[i.first];
      res += x * (x + 1) / 2;
      // cout << "first method counted " <<  x * (x + 1) / 2 << endl;
      ll p1 = count[a];
      ll p2 = count[b];
      // cout << "count of " << a << "is " << count[a] << endl;
      // cout << "count of " << b << "is " << count[b] << endl;
      // cout << "second method counted " <<  p1 * x  << endl;
      res += p1 * x;
      if (a != b) {
        // cout << "second method counted additional " <<  p2 * x  << endl;
        res += p2 * x;
      }
    }
  }

  cout << res << '\n';
 }
 return 0;
}