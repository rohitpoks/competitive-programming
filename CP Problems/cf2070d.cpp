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

static const int MOD = 998244353;

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<set<int> > tree(n + 1);
  for (int i  = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    tree[x].insert(i + 2);
  }

  // cout << endl;
  queue<int> q;
  q.push(1);
  int level = 1;
  map<int, set<int> > nodes_at_level;
  map<int, int> level_of_node;
  while (!q.empty()) {
    int s = q.size();
    for (int i = 0; i < s; i++) {
      int next = q.front();
      q.pop();
      nodes_at_level[level].insert(next);
      level_of_node[next] = level;
      for (int n : tree[next]) q.push(n);
    }

    level++;
  }

  auto current = nodes_at_level.end();
  ll sum_next_level = 0;
  vector<ll> dp(n + 1, 0);
  // for each level
  while ((--current)->first != 1) {
    // for every vertex u in level
    ll sum_current_level = 0;
    for (int u : current->second) {
      dp[u] = sum_next_level + 1;
      for (int n : tree[u]) {
        // subtract the sum from the child
        dp[u] -= dp[n];
        if (dp[u] < 0) dp[u] += MOD;
      }

      dp[u] %= MOD;
      if (dp[u] < 0) dp[u] += MOD;
      sum_current_level += dp[u];
      sum_current_level %= MOD;
      if (sum_current_level < 0) sum_current_level += MOD;
    }

    sum_next_level = sum_current_level;
  }

  dp[1] = 1;
  for (int i : tree[1]) {
    dp[1] += dp[i];
    dp[1] %= MOD;
    if (dp[1] < 0) dp[1] += MOD;
  }
  cout << dp[1] << '\n';

 }

 return 0;
}