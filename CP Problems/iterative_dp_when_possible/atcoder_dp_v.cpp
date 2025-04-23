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

using ll = unsigned long long int;
using namespace std;

ll dp(ll root, bool b, bool can_color_child_black, ll p, vector<vector<ll> >& tree, vector<vector<vector<ll > > >& memo) {
  if ((!b) && (!can_color_child_black)) return memo[root][b][can_color_child_black] = 1;

  if (memo[root][b][can_color_child_black] != -1) {
    return memo[root][b][can_color_child_black];
  }

  ll res = 1;
  if (b) {
    // need to color root black
    for (ll c: tree[root]) {
      if (c == p) continue;
      res *= (1 + dp(c, 1, 1, root, tree, memo));
    }

    dp(root, 0, 1, p, tree, memo);
    dp(root, 0, 0, p, tree, memo);
    return memo[root][b][can_color_child_black] = res;
  }

  // need to color root white, can color children black
  for (ll c : tree[root]) {
    if (c == p) continue;
    res *= dp(c, 1, 1, root, tree, memo);
  }

  res++;
  return memo[root][b][can_color_child_black] = res;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 ll n, m;
 cin >> n >> m;
 vector<vector<ll> > tree(n + 1);
 for (int i = 0; i < n - 1; i++) {
  ll u, v;
  cin >> u >> v;
  tree[u].push_back(v);
  tree[v].push_back(u);
 }

 // arbitrarily root the tree at 1
 vector<vector<vector<ll> > > memo(n + 100, vector<vector<ll > >(2, vector<ll>(2, -1)));
 memo[1][1][1] = dp(1, 1, 1, -1, tree, memo);
 memo[1][0][0] = dp(1, 0, 0, -1, tree, memo);
 memo[1][0][1] = dp(1, 0, 1, -1, tree, memo);
 queue<pair<ll, ll> > q;
 // queue of root, parent
 vector<ll> ans(n + 1, 0);
 ans[1] = memo[1][1][1];
 q.push({1, -1});
 while (!q.empty()) {
  int s = q.size();
  for (int i = 0; i < s; i++) {
    auto [next, parent] = q.front();
    if (next != 1) {
      assert(memo[next][1][1] != -1);
      assert(memo[next][0][0] != -1);
      assert(memo[next][1][1] != -1);
      ans[next] = memo[next][1][1] + (ans[parent] * memo[next][1][1])/(memo[next][0][0] + memo[next][1][1]);
    }

    q.pop();
    for (ll n : tree[next]) {
      if (n == parent) continue;
      q.push({n, next});
    }
  }
 }

 for (int i = 1; i <= n; i++) {
  ll res = (ans[i]) % m;
  if (res < 0) res += m;
  cout << res << '\n';
 }
 return 0;
}