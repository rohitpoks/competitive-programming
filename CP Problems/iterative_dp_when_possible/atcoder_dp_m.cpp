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

ll MOD = 1e9 + 7;

int main() {
 ios_base::sync_with_stdio(false);
 int n, k;
 cin >> n >> k;
 vector<ll> a(n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }

 // dp[i][k] -> number of ways to distribute k candies among
 // children from 0 through i
 // dp[i][k] = dp[i-1][j] for all j = 0...a_i
 vector<vector<ll> > memo(n + 1, vector<ll>(k + 1, 0));
 vector<vector<ll> > psum(n + 1, vector<ll>(k + 3, 0));
 // to get values from i to j for row r, do psum[r][j + 1] - psum[r][i]
 // psum[i][j] -> sum of values in row i for columns 0 through j - 1
 for (int i = 0; i <= a[0]; i++) {
  // ways of distributing exactly i chocolates to first child: 0
  memo[0][i] = 1;
  psum[0][i + 1] = psum[0][i] + 1;
  psum[0][i + 1] %= MOD;
  if (psum[0][i+1] < 0) psum[0][i+1] += MOD;
 }

 for (int j = a[0] + 1; j <= k + 1; j++) {
  psum[0][j + 1] = psum[0][j];
  psum[0][j+1] %= MOD;
  if (psum[0][j+1] < 0) psum[0][j+1] += MOD;
 }             

 for (ll i = 1; i < n; i++) {
  for (ll p = 0; p <= k; p++) {
    // i want to distribute p candies to people from 0 through i
    // this can be done by distributing 0 candies to person i = memo[i - 1][p]
    // or 1 candy to person i = memo[i-1][p-1]
    // all the way up to a[i] candies to person i
    // memo[i-1][p-a[i]]
    // person 0: i want to distribute candies ranging from p - a[i] (all candies for myslef) to p (no candies for myself)
    memo[i][p] += (psum[i-1][p + 1] - psum[i-1][max(p - a[i], (ll) 0)]);
    memo[i][p] %= MOD;
    if (memo[i][p] < 0) memo[i][p] += MOD;
    psum[i][p + 1] = psum[i][p] + memo[i][p];
    psum[i][p+1] %= MOD;
    if (psum[i][p + 1] < 0) psum[i][p+1] %= MOD;
  }
 }

 cout << memo[n - 1][k] << endl;
 return 0;
}