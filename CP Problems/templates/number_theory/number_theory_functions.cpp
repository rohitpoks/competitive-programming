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
 return 0;
}

/**
 * @return (a ^ n) mod p, p doesn't have to be prime
 * ll ans = (2, 5, 7);
 * // ans = 4
 * @endcode
 */
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