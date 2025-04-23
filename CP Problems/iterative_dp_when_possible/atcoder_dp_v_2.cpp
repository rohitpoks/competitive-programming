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

ll populate_memo(ll r, ll p, vector<vector<ll> >& tree, vector<ll>& dp) {
  ll res = 1;
  for (int c : tree[r]) {
    if (c != p) res *= populate_memo(c, r, tree, dp);
  }

  return dp[r] = 1 + res;
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

 vector<ll > dp(n + 1, -1);
 dp[1] = populate_memo(1, -1, tree, dp);
 cout << dp[1] - 1 << endl;
 return 0;
}