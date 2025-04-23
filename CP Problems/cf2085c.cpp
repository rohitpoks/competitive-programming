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

ll solve(ll a, ll b) {
  // if (__builtin_clzll(a) == __builtin_clzll(b)) {
  //   return -1;
  // }

  ll res = 0;
  vector<int> bits;
  ll car = 0;
  if (a < b) {
    ll t = a;
    a = b;
    b = t;
  }

  ll p = a;
  while (a > 0) {
    ll bit = a & 1;
    if (car + bit == 2) {
      car = 1;
      bits.push_back(0);
    } else {
      bits.push_back(car + bit);
      car = (bits.back() + bit + car) > 1;
    }
    a /= 2;
  }

  ll cur = 1;
  for (int i = 0; i < bits.size(); i++) {
    res += cur * (bits[i]);
    cur *= 2;
  }

  // cout << (a + res + b + res) << endl;
  if ((p + res + b + res) != ((p + res) ^ (b + res))) return -1;
  return res;

}



void test() {
  std::srand(std::time(0));
  while (1) {
    ll a = (std::rand() % 100) + 1;
    ll b = (std::rand() % 100) + 1;
    ll k = solve(a, b);
    if (k == -1) {
      for (int i = 1; i <= 1000; i++) {
        if (((a + i) ^ (b + i)) == (a + b + i + i)) {
          cout << "counterexample:" << endl;
          cout << a << ' ' << b << ' ' << i << endl;
          return;
        }

      }
    }

    if (((a + k) ^(b + k)) != (a + b + k + k)) {
      cout << a << ' ' << b << endl;
      return;
    }
  }
} 


int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
//  test();
 int t;
 cin >> t;
 while (t--) {
  ll a, b;
  cin >> a >> b;
  cout << solve(a, b) << '\n';
 }

 return 0;
}