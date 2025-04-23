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

static const ll MOD = 1e9 + 7;

int memo(vector<vector<int> > & tree, int v, bool color, map<int, int>& node_to_level, vector<vector<ll> >& dp) {
  // color = 0: color root white
  // color = 1: color root black
  ll res = 1;
  if (dp[v][color] != -1) return dp[v][color];
  for (int n : tree[v]) {
    if (node_to_level[n] != (node_to_level[v] + 1)) continue;
    // if root is 1 or 0, can always color child 0
    // 0
    if (color) {
      // must color children white
      res *= memo(tree, n, 0, node_to_level, dp);
      res %= MOD;
    } else {
      // can color children either white or black
      ll opt_1 = memo(tree, n, 0, node_to_level, dp);
      ll opt_2 = memo(tree, n, 1, node_to_level, dp);
      res *= (opt_1 + opt_2);
      res %= MOD;
    }
  }

  return dp[v][color] = res;
}
int main() {
 ios_base::sync_with_stdio(false);
// root tree at vertex 0, label each vertex w. a level to denote parent child relationship
 int n;
 cin >> n;
 vector<vector<int> > adj(n);
 for (int i = 0; i < n - 1; i++) {
  int u, v;
  cin >> u >> v;
  u--;
  v--;
  adj[u].push_back(v);
  adj[v].push_back(u);
 }

 map<int, int> vertex_to_level;
 queue<int> q;
 q.push(0);
 int level = 0;
 vertex_to_level[0] = 0;
 while (!q.empty()) {
  int size = q.size();
  for (int i = 0; i < size; i++) {
    int next = q.front();
    q.pop();
    for (int n : adj[next]) {
      if (!vertex_to_level.count(n)) {
        q.push(n);
        vertex_to_level[n] = level + 1;
      }
    }
  }

  level++;
 }

 vector<vector<ll > > dp(n + 1, vector<ll>(2, -1));
 ll res = memo(adj, 0, 0, vertex_to_level, dp) + memo(adj, 0, 1, vertex_to_level, dp);
 res %= MOD;
 cout << res;
 return 0;
}