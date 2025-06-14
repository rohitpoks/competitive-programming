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
 // 0 4, 1 2, 2 2
 // idea: jump whenever you can
 // counterexample:
 // 0 1, 0 1, 0 0
 // 1 2, 2 3, 2 4, 4 5
 //  1    1    0    -1
 // actual: 1 2, 3 4, 3 4, 4 6

 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> d(n);
  vector<pair<int, int> > h(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  for (int i = 0; i < n; i++) {
    cin  >> h[i].first >> h[i].second;
  }

  vector<pair<int, int> > actual;
  int l = 0;
  int r = 0;
  if (d[0] == 1 || d[0] == -1) r = 1;
  if (d[0] == 1) l = 1;
  // find overlap
  l = max(l, h[0].first);
  r = min(r, h[0].second);
  actual.push_back({l, r});
  for (int i = 1; i < n; i++) {
    // adjust l, r based on d
    if (d[i] == 1) {
      l++;
      r++;
    } else if (d[i] == -1) {
      r++;
    }

    l = max(l, h[i].first);
    r = min(r, h[i].second);
    actual.push_back({l, r});
  }

  // actual: list of possible intervals
  bool not_possible = actual.back().first > actual.back().second;
  int cur = actual.back().first;
  vector<int> res;
  for (int i = n - 1; i > 0; i--) {
    if (actual[i].first > actual[i].second) not_possible = true;
    if (d[i] != -1) {
      res.push_back(d[i]);
      cur -= d[i];
      continue;
    }

    if (cur <= actual[i - 1].second) res.push_back(0);
    else {
      res.push_back(1);
      cur--;
    }
  }

  if (d[0] != -1) {
    res.push_back(d[0]);
  } else {
    if (cur <= 0) res.push_back(0);
    else res.push_back(1);
  }

  reverse(res.begin(), res.end());
  if (not_possible) cout << -1 << '\n';
  else {
    for (int i : res) cout << i << ' ';
    cout << '\n';
  }
 }
 return 0;
}