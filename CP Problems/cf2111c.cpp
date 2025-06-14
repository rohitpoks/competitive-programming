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
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  // given an index i, what's the corresponding left index where a_i ends
  vector<int> left(n, 0);
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i-1]) left[i] = left[i - 1];
    else left[i] = i;
  }

  ll res = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    ll cur = n - (i - left[i] + 1);
    cur *= (ll) a[i];
    res = min(res, cur);
  }

  cout << res << '\n';
 }
 return 0;
}