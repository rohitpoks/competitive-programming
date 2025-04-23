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
  int n;
  cin >> n;
  // store (x, -y)
  set<pair<ll, ll> > points;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    points.insert({-y, x});
  }

  // start with the top left and keep reverting
  while (points.size() > 1) {
    auto next = *points.begin();
    ll x = next.second;
    ll y = -next.first;
    y--;
    vector<pair<ll, ll> > steps = {{1, 0}, {0, 1}, {1, -1}, {0, 0}};
    for (const auto& s : steps) {
      pair<ll, ll> neighbor = {-(y + s.second), x + s.first};
      if (points.count(neighbor))
        points.erase(neighbor);
      else
        points.insert(neighbor);
    }
  }

  cout << points.begin()->second << ' ' << -points.begin()->first << '\n';
 }
 return 0;
}