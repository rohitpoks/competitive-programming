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
 // dp[i][j] = length of longest subsequence for s1[i:] and s2[j:]
 // if s[i] = s[j] dp[i][j] 1 + dp[i+1][j+1]
 // else if not equal then dp[i][j] = max(dp[i+1][j], dp[i][j+1])
 // base case: dp[s1.length()][k] = 0
 // base case 2: dp[k][s2.length()] = 0
 string s1, s2;
 cin >> s1 >> s2;
 vector<vector<int> > dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
 for (int i = s1.size() - 1; i >= 0; i--) {
  for (int j = s2.size() - 1; j >= 0; j--) {
    if (s1[i] == s2[j]) dp[i][j] = 1 + dp[i+1][j+1];
    else {
      dp[i][j] = max(dp[i+1][j], dp[i][j]);
      dp[i][j] = max(dp[i][j+1], dp[i][j]);
    }
  }
 }
 // use backtracking to find ans
 // always start at the 'solution to the problem'
 int i = 0;
 int j = 0;
 string res = "";
 while (i < s1.size() && j < s2.size()) {
  // figure out which dp relation you used at this particular i and j
  if (s1[i] == s2[j]) {
    // we know we used 1 + dp[i + 1][j + 1]
    res += s1[i];
    i++;
    j++;
  } else {
    // we know we used either one of dp[i + 1][j], dp[j+1][i]
    // we need to decide which one we used exactly
    if (dp[i][j] == dp[i + 1][j]) i++;
    else j++;
  }
 }
  cout << res;
 return 0;
}