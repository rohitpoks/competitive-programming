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

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  ll m, x;
  cin >> m >> x;
  // largest affordable happyness first
  vector<ll> happyness(m);
  vector<ll> cost(m);
  ll max_h = 0;
  for (ll i = 0; i < m; i++) {
    cin >> cost[i] >> happyness[i];
    max_h += happyness[i];
  }

  vector<vector<ll> > memo(m + 1, vector<ll>(max_h + 1, LLONG_MAX));
  // when happyness is 0: cost is 0
  for (ll i = 0; i < m; i++) {
    memo[i][0] = 0;
  }

  // for index 0, happyness[0] comes with min cost cost[0]
  if (cost[0] == 0) memo[0][happyness[0]] = 0;

  for (ll h = 1; h <= max_h; h++) {
    for (ll i = 1; i < m; i++) {
      memo[i][h] = memo[i - 1][h];
      // need to make sure i can actually afford the cost
      
      if ((h - happyness[i] >= 0) && memo[i-1][h - happyness[i]] < LLONG_MAX) {
        ll cur_h_cost = memo[i-1][h-happyness[i]] + (ll) cost[i];
        if (cur_h_cost <= x * i) memo[i][h] = min(memo[i][h], cur_h_cost);
      }
    }
  }

  for (ll i = max_h; i >= 0; i--) {
    // min total cost to obtain happyness m-1 is less than total cost
    if (memo[m-1][i] <= (m - 1) * x) {
      cout << i << '\n';
      break;
    }
  }
 }

 return 0;
}