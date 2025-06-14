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

void generate_primes(ll n, vector<ll>& res) {
  // GENERATE FIRST N PRIMES, N*(log(log(N)))
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }

    if (is_prime[i]) res.push_back(i);
  }
}



int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 ll   t;
 cin >> t;
 vector<ll> primes;
 generate_primes(6e6, primes);
 while (t--) {
  ll n;
  cin >> n;
  ll total = 0;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
    total += arr[i];
  }


  if (n == 1) {
    cout << 0 << '\n';
    continue;
  }

  sort(arr.begin(), arr.end(), greater<ll>());
  ll sum_a = 0;
  ll sum_p = 0;
  ll res = 0;
  for (ll i = 0; i < min(primes.size(), arr.size()); i++) {
    sum_p += primes[i];
    sum_a += arr[i];
    if (sum_a >= sum_p) res = i + 1;
  }

  cout << n - res << '\n';
 }
 return 0;
}