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
 ll test_no = 0;
 while (t--) {
  test_no++;
  ll n, m, l;
  cin >> n >> m >> l;
  ll total = 0;
  ll smallest_even = LLONG_MAX;
  ll smallest_odd = LLONG_MAX;
  vector<ll> a(l);
  for (ll i = 0; i < l; i++) {
    cin >> a[i];
    total += a[i];
    if (a[i] % 2 == 0) smallest_even = min(smallest_even, a[i]);
    else smallest_odd = min(smallest_odd, a[i]);
  }

  vector<vector<ll> > g(n + 1);
  for (ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // if (test_no==75) {
  //   // for (int i = 0; i < n; i++) {
  //   //   for (int j : g[i]) {
  //   //     cout << i << "->" << j << ",";
  //   //   }
  //   // }

  //   for (ll i : a) cout << i << ",";
  //   cout << endl;
  // }

  queue<ll> q;
  set<ll> seen_even;
  set<ll> seen_odd;
  seen_even.insert(1);
  q.push(1);
  vector<vector<ll> > dist(n + 1, vector<ll>(2, LLONG_MAX));
  dist[1][0] = 0;
  ll d = 0;
  while (!q.empty()) {
    ll s = q.size();
    for (ll i = 0; i < s; i++) {
      ll next = q.front();
      q.pop();
      if (dist[next][d % 2] == LLONG_MAX) dist[next][d%2] = d;
      for (ll n : g[next]) {
        if (dist[next][0] != LLONG_MAX) {
          dist[n][1] = min(dist[n][1], dist[next][0] + 1);
        }

        if (dist[next][1] != LLONG_MAX) {
          dist[n][0] = min(dist[n][0], dist[next][1] + 1);
        }

        if (!seen_even.count(n) && dist[n][0] != LLONG_MAX) {
          seen_even.insert(n);
          q.push(n);
        }

        if (!seen_odd.count(n) && dist[n][1] != LLONG_MAX) {
          seen_odd.insert(n);
          q.push(n);
        }
      }
    }

    d++;
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << dist[i][0] << ',' << dist[i][1] << endl;
  // }

  // cout << "total is " << total << endl;
  // cout << "even is " << smallest_even << endl;
  // cout << "odd is " << smallest_odd << endl;
  vector<bool> p(n + 1, false);
  for (ll i = 1; i <= n; i++) {
    ll e = dist[i][0];
    ll o = dist[i][1];
    // cout << "now investingating: " << i << endl;
    if (total < min(e, o)) {
      continue;
    } else if (total >= max(e, o)) {
      p[i] = 1;
      continue;
    }

    if (o < e) {
      if (total % 2 == 1) p[i] = 1;
      if (smallest_odd == LLONG_MAX) continue;
      if (((total - smallest_odd) >= o)) {
        // cout << "got here" << endl;
        p[i] = 1;
      }
    } else {
      if (total % 2 == 0) p[i] = 1;
      if (smallest_odd == LLONG_MAX) continue;
      if ((total - smallest_odd >= e)) p[i] = 1;
    }
  }

  for (ll i = 1; i  <= n; i++) {
    if (p[i]) cout << '1';
    else cout << '0';
  }

  cout << '\n';
 }
 return 0;
}