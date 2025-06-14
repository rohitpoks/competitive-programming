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

ll b_search(vector<ll>& colors, ll t) {
  int l = 0;
  int r = colors.size();
  // index of paint that is >= t
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (colors[m] >= t) r = m;
    else l = m;
  }

  if (colors[l] >= t) return l;
  return r;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  vector<ll> colors(m);
  for (int i = 0; i < m; i++) {
    cin >> colors[i];
  }

  sort(colors.begin(), colors.end());
  // bsearch for smallest x >= t
  ll res = 0;
  for (int l = 1; l < n; l++) {
    int r = n - l;
    ll count_l = m - b_search(colors, l);
    ll count_r = m - b_search(colors, r);
    if (count_l && count_r) {
      res += (count_l * count_r) - min(count_l, count_r);
    }
  }

  cout << res << '\n';
 }
 return 0;
}