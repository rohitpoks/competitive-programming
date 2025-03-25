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
 
bool dp(int top_index, int bottom_index, vector<vector<char> >& matrix, bool& multiple, vector<vector<signed char> >& memo) {
  // guarantee that bottom_index and top_index will be within 2 of each other
  // matrix[index][0 for top, 1 for bottom]
  // cout << "at index " << top_index << "," << bottom_index << endl;
  int diff = top_index - bottom_index;
  diff += 2;
  if (top_index >= matrix.size() && bottom_index >= matrix.size()) return 1;
  if (memo[top_index][diff] != -1) return memo[top_index][diff];
  ll ans = 0;
  if (top_index == bottom_index) {
    int i = top_index;
    if ((i < (matrix.size() - 1) && matrix[i][0] == '.') && (matrix[i+1][0] == '.') && (matrix[i][1] == '.') && (matrix[i+1][1] == '.')) multiple = true;
    if (matrix[top_index][0] == matrix[bottom_index][1] && matrix[top_index][0] == '.') ans += dp(top_index + 1, bottom_index + 1, matrix, multiple, memo);
    if (matrix[top_index][0] == '.' && (top_index + 1) < matrix.size() && matrix[top_index + 1][0] == '.') ans += dp(top_index + 2, bottom_index, matrix, multiple, memo);
    if (matrix[bottom_index][1] == '.' && (bottom_index + 1) < matrix.size() && matrix[bottom_index + 1][1] == '.') ans += dp(top_index, bottom_index + 2, matrix, multiple, memo);
    // skip the 'hash'
    if (matrix[top_index][0] == '#') ans += dp(top_index + 1, bottom_index, matrix, multiple, memo);
    // hash at bottom
    else if (matrix[bottom_index][1] == '#') ans += dp(top_index, bottom_index + 1, matrix, multiple, memo);
    return memo[top_index][diff] = (ans > 0);
  } else if (top_index < bottom_index) {
    // process top_index first
    // cannot place vertical, can only place horizontal
    if (matrix[top_index][0] == '#') return memo[top_index][diff] = dp(top_index + 1, bottom_index, matrix, multiple, memo);
    if (top_index + 1 < matrix.size() && matrix[top_index + 1][0] == '.') return memo[top_index][diff] = dp(top_index + 2, bottom_index, matrix, multiple, memo);
    return memo[top_index][diff] = 0;
  } else {
    // process bottom index first
    // cannot place vertical, can only place horizontal
    if (matrix[bottom_index][1] == '#') return memo[top_index][diff] = dp(top_index, bottom_index + 1, matrix, multiple, memo);
    if (bottom_index + 1 < matrix.size() && matrix[bottom_index + 1][1] == '.') return memo[top_index][diff] = dp(top_index, bottom_index + 2, matrix, multiple, memo);
    return memo[top_index][diff] = 0;
  }
}
 
int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<vector<char> > matrix(n, vector<char>(2));
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    matrix[i][0] = s1[i];
    matrix[i][1] = s2[i];
  }
 
  bool multiple = false;
  vector<vector<signed char> > memo(matrix.size() + 1, vector<signed char>(6, -1));
  bool ans = dp(0, 0, matrix, multiple, memo);
  if (ans == 0) cout << "None";
  else {
    if (multiple) cout << "Multiple";
    else cout << "Unique";
  }
 
  cout << '\n';
 }
 return 0;
}