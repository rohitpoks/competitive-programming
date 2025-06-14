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

 int n;
 cin >> n;
 vector<int> h(n, 0);
 vector<int> a(n, INT_MIN);
 vector<int> m(n, INT_MAX);
 for (int i = 0; i < n; i++) {
  cin >> h[i];
 }

 // precompute a
 // a[i]: min(a[i + 1], a[i + 2], ..., a[n - 1])3
 for (int i = n - 2; i >= 0; i--) {
  a[i] = min(a[i + 1], h[i + 1]);
 }

 // precompute m (optional step, we can also do this with just one variable in the next for loop)
 // m[i]: min(a[i - 1], a[i - 2], ..., a[0])
 for (int i = 1; i < n; i++) {
  m[i] = min(m[i - 1], h[i - 1]);
 }

 int res = 0;
 for (int i = 0; i < n; i++) {
  if (m[i] < h[i] && a[i] > h[i]) res++;
 }

 cout << res;
 return 0;
}