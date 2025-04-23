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
#include <iomanip>

using ll = long long;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  // dp[i][k] -> prob. of having exactly k heads if we are considering coins 0, 1, 2, .., i
  // dp[i][k] -> 2 options: either flip this heads or flip it tails
  // dp[i][k] = prob_i * dp[i-1][k-1] + (1 - prob_i) * dp[i-1][k]
  // base case: dp[i][0] -> all tails from 0 through i -> prod. of 1-prob_l for all l = 0 to i
  // dp[0][0] = 1 - prob_0
  // dp[0][1] = prob_0
  int n;
  cin >> n;
  vector<long double> prob(n);
  for (int i = 0; i < n; i++) {
    cin >> prob[i];
  }

  vector<vector<long double> > dp(n + 1, vector<long double>(n + 1, 0));
  long double prod = 1;
  for (int i = 0; i < n; i++) {
    prod *= (1 - prob[i]);
    dp[i][0] = prod;
  }

  dp[0][1] = prob[0];
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = prob[i] * dp[i-1][j-1] + (1-prob[i]) * dp[i-1][j];
    }
  }

  long double res = 0;
  int half = n / 2;
  half++;
  for (int i = half; i <= n; i++) {
    res += dp[n - 1][i];
  }

  std::cout << std::setprecision(10) << res;
  return 0;
}