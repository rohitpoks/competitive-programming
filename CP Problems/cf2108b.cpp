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

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, x;
  cin >> n >> x;
  if (n == 1 && x == 0) {
    cout << -1 << '\n';
    continue;
  }
  int prev = 0;
  ll cur = 1;
  ll res = 0;
  ll total = 0;
  while (x > 0) {
    if (x % 2) {
      if (cur == 1) prev++;
      res += cur;
      total++;
    }

    cur *= 2;
    x /= 2;
  }

  // 0 0
  // 0 0
  // ----
  // 0 1
  int rem = n - total;
  if (rem % 2 && rem > 0) {
    res += rem - 1;
    prev += rem - 1;
    // one remaining row of 0s
    // prev: how many lsbs were previously set
    if (prev < n - 1) {
      res += 2;
    } else {
      // no 1 remaining so add 2 instead
      res += 4;
    }
  } else if (rem > 0) {
    res += rem;
  }

  cout << res << '\n';
 }
 return 0;

}