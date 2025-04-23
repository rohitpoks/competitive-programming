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
 ll v_max = 0;
 for (int i = 0; i < n; i++) {
  cin >> weights[i];
  cin >> values[i];
  v_max += values[i];
 }

 // memo[v][i] -> min weight to get sum of values exactly equal to v from indices 0, 1, ..., i

 // memo[v][i] -> min(memo[v][i-1], memo[v-value[i]][i-1] + cost[i])

 vector<vector<ll> > memo(v_max + 1, vector<ll>(n, LONG_MAX));
 // base case: to get value 0, min weight is exactly 0
 // setting base case for value 0 -> values must begin to increase from 0
 for (int i = 0; i < n; i++) {
  memo[0][i] = 0;
 }

 memo[values[0]][0] = weights[0];

 for (int v = 1; v <= v_max; v++) {
  for (int i = 1; i < n; i++) {
    memo[v][i] = memo[v][i-1];
    if ((v - values[i] >= 0) && memo[v-values[i]][i-1] < LONG_MAX) memo[v][i] = min(memo[v][i], memo[v-values[i]][i-1] + (ll) weights[i]);
  }
 }


 for (int i = v_max; i >= 0; i--) {
  if (memo[i][n - 1] <= w) {
    cout << i;
    break;
  }
 }
 return 0;
}