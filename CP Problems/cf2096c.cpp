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

vector<vector<ll> > transpose(vector<vector<ll> >& matrix) {
  vector<vector<ll> > r(matrix.size(), vector<ll>(matrix.size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix.size(); j++) {
      r[j][i] = matrix[i][j];
    }
  }

  return r;
}

ll dp(vector<vector<ll > >& matrix, bool prev_row_offset, int row, vector<ll>& costs, vector<vector<ll> >& memo) {
  int n = matrix.size();
  if (row >= n) return 0;
  if (memo[row][prev_row_offset] != -1)  return memo[row][prev_row_offset];
  // option 1: increase row
  // option 2: don't increase row
  vector<ll> res(2, LLONG_MAX);
  for (int increase = 0; increase <= 1; increase++) {
    bool should_continue = false;
    for (int i = 0; i < n; i++) {
      if (increase + matrix[row][i] == prev_row_offset + matrix[row - 1][i]) {
        should_continue = true;
      }
    }

    if (should_continue) continue;
    ll next = dp(matrix, increase, row + 1, costs, memo);
    if (next == LLONG_MAX) continue;
    if (increase) next += costs[row];
    res[increase] = next;
  }

  return memo[row][prev_row_offset] = min(res[0], res[1]);
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<vector<ll> > matrix(n, vector<ll>(n));
  vector<ll> costs(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> costs[i];
  }


  vector<vector<ll> > memo(matrix.size(), vector<ll>(2, -1));
  ll vertical = dp(matrix, false, 1, costs, memo);
  if (dp(matrix, true, 1, costs, memo) != LLONG_MAX) {
    vertical = min(vertical, dp(matrix, true, 1, costs, memo) + costs[0]);
  }
  for (int i = 0; i < n; i++) {
    cin >> costs[i];
  }

  matrix = transpose(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j <= 1; j++) {
      memo[i][j] = -1;
    }
  }

  ll horizontal = dp(matrix, false, 1, costs, memo);
  if (dp(matrix, true, 1, costs, memo) != LLONG_MAX) {
    horizontal = min(horizontal, dp(matrix, true, 1, costs, memo) + costs[0]);
  }

  if (vertical == LLONG_MAX || horizontal == LLONG_MAX) {
    cout << -1 << '\n';
    continue;
  }

  cout << horizontal + vertical << '\n';
 }

 return 0;
}