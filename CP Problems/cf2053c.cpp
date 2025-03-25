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

pair<ll, ll> interval_sum(int l, int r, int k) {
  // first in pair: sum of elements, second in pair: how many elements used
  int length = r - l + 1;
  if (length < k) return {0, 0};
  ll m = (r + l) / 2;
  if (length % 2 == 0) {
    // even length
    pair<ll, ll> left = interval_sum(l, m, k);
    // for each element, offset it by length / 2
    left.first += left.first + ((ll) left.second * (ll) length / 2);
    left.second *= 2;
    return left;
  } else {
    // add middle element
    pair<ll, ll> left = interval_sum(l, m - 1, k);
    left.first += left.first + (ll) left.second * (ll) m;
    left.first += m;
    left.second *= 2;
    left.second++;
    return left;
  }
}
int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int l = 1;
  int r;
  cin >> r;
  int k;
  cin >> k;
  pair<ll, ll> res = interval_sum(1, r, k);
  cout << res.first << '\n';
 }
 return 0;
}