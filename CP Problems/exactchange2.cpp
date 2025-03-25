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

pair<int, int> dp(vector<int>& coins, int p, map<pair<int, int>, pair<int, int> >& memo, int index) {

  // return price, number of coins
  if (memo.count({p, index})) return memo[{p, index}];
  if (p <= 0) {
    // cout << "got here, returning " << -p << endl;
    return memo[{p, index}] = {-p, 0};
  }

  if (index >= coins.size()) return {INT_MAX, INT_MAX};
  // can either use coins at index or not
  int coin = coins[index];
  pair<int, int> cur = dp(coins, p - coin, memo, index + 1);
  pair<int, int> next = dp(coins, p, memo, index + 1);
  if (cur.second != INT_MAX) cur.second++;

  pair<int, int> best = cur;
  if (next < cur) best = next;
  return memo[{p, index}] = best;
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int p;
  cin >> p;
  int n;
  cin >> n;
  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  map<pair<int, int>, pair<int, int> > memo;
  pair<int, int> res = dp(coins, p, memo, 0);
  cout << res.first + p << " " << res.second << '\n';
 }

 return 0;
}