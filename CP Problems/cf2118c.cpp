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
#include <stack>
#include <cassert>

using ll = long long;
using uint = unsigned int;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  // allocate first to every number whose 1st bit is not set
  // then to every number whose 2nd bit is not set
  // keep doing this until negative k
  ll n, k;
  cin >> n >> k;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll cur = 1;
  ll res = 0;
  while (k >= cur) {
    for (int i = 0; i < n; i++) {
      if (k - cur >= 0 && !(cur & arr[i])) {
        res++;
        k -= cur;
      }
    }

    cur *= 2;
  }

  // add already existing bits
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) res += __builtin_popcountll(arr[i]);
  }

  cout << res << '\n';
 }
 return 0;
}