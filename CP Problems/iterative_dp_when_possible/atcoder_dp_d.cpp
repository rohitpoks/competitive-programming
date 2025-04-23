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
 int n, w;
 cin >> n >> w;
 vector<ll> weights(n);
 vector<ll> values(n);
 ll w_max = w;
 for (int i = 0; i < n; i++) {
  cin >> weights[i];
  cin >> values[i];
 }

 // can memoize on weights
 // memo[w][i] -> max sum of values if capacity w and eligible indices are 0, 1, .. i
 // memo[w][i] = memo[w][i - 1];
 // if (w - weights[i] >= 0) memo[w][i] = max(memo[w][i], values[i] + memo[w - weights[i]][i - 1])
 // initialize all memo[0][w], w >= weight[0] to v[0] and 0 otherwise
 // return memo[W_MAX][n - 1]
 vector<vector<ll> > memo(w + 1, vector<ll>(n, 0));
 for (int i = weights[0]; i <= w; i++) {
  memo[i][0] = values[0];
 }

 for (int i = 1; i < n; i++) {
  for (int w = 0; w <= w_max; w++) {
    memo[w][i] = memo[w][i - 1];
    if (w - weights[i] >= 0) {
      memo[w][i] = max(memo[w][i], values[i] + memo[w - weights[i]][i - 1]);
    }
  }
 }

  cout << memo[w_max][n-1];
 return 0;
}