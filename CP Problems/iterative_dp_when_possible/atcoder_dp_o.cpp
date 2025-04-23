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

int set_bit(int bit_num) {
  int res = 1;
  for (int i = 0; i < bit_num; i++) {
    res <<= 1;
  }

  return res;
}

int main() {
 ios_base::sync_with_stdio(false);
 int n;
 cin >> n;
 vector<vector<bool> > adj(n, vector<bool>(n, false));
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < n; j++) {
    int x;
    cin >> x;
    adj[i][j] = x;
  }
 }

 vector<ll> dp((int) pow(2, 21) + 1, 0);
 // dp[selection]: if can select men from index 0 to max_bits in selection, how many pairings do i have?
 // dp[101010] = dp[101000] + dp[100010]
 for (int j = 0; j < n; j++) {
  // base case: define injective functions for i = 0
  if (adj[0][j]) {
    dp[set_bit(j)]++;
  }
 }

 // 21 1's: max is 2^21 - 1
 for (int selection = 1; selection <= (int) pow(2, n) - 1; selection++) {
  set<int> set_bits;
  int x = selection;
  int mask = 1;
  int total = 0;
  for (int i = 1; i <= n; i++) {
    if (mask & selection) {
      total++;
    }

    mask <<= 1;
  }

  if (total <= 1) continue;
  mask = 1;
  for (int i = 1; i <= n; i++) {
    if ((mask & selection) && (adj[total - 1][i - 1])) dp[selection] += dp[selection - set_bit(i - 1)];
    mask <<= 1;
    dp[selection] %= MOD;
  }
 }
 // this should be 1, as person 1 can ONLY pair up with 3 in this case
 cout << dp[pow(2, n) - 1];
 return 0;
}