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
 int t;
 cin >> t;
 while (t--) {
  int n, x;
  cin >> n >> x;
  set<int> unique_even_factors;
  ll l = x;
  ll u = n;
  ll t1 = n - x;
  set<ll> ans;

  if (((n + x - 2) % 2 == 0))
    ans.insert(n + x - 2);

  if (((n - x) % 2 == 0))
    ans.insert(n - x);

  for (ll i = 1; i <= (int) sqrt(n + x - 2); i++) {
    if ((n + x - 2) % i != 0) continue;
    if ((i % 2) == 0) {
      ans.insert(i);
    }

    if ((((n + x - 2) / i) % 2 == 0)) {
      ans.insert((n + x - 2) / i);
    }
  }
  
  for (ll i = 1; i <= (int) sqrt(n - x); i++) {
    if ((n - x) % i != 0) continue;

    // i and (n - x) / i are divisors
    if ((i % 2 == 0)) {
      ans.insert(i);
    }

    if (((n - x) / i) % 2 == 0) {
      ans.insert((n - x) / i);
    }
  }

  int res = 0;
  for (ll i : ans) {
    if (((i + 2) / 2 >= x) && ((i + 2) / 2 <= n)) {
      res++;
    }
    
  }

  cout << res << '\n';
 }
 return 0;
}