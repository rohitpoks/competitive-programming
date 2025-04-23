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
 int n;
 cin >> n;
 vector<ll> arr(n);
 vector<ll> psum;
 psum.push_back(0);
 for (int i = 0; i < n; i++) {
  cin >> arr[i];
  psum.push_back(psum.back() + arr[i]);
 }

 vector<vector<ll> > dp(n + 1, vector<ll>(n + 1));
 // dp[i][j] -> maximize current player's score if p1 can take from i...j
 // this can be done in the following way
 // option 1: pick i. in this case, player 2's score is dp[i+1][j]
 // option 2: pick j. in this case, player 2's score is dp[i][j-1]
 // dp[i][j] = max(arr[i] + comp(dp[i+1][j]), arr[j] + comp(dp[i][j-1]))
 // note that larger i's need to be computed first and smaller j's need to be computed first
 // p1's total score is hence the 'complement' of p2's score
 // with this information, p1 can make the optimal deciison
 for (int i = 0; i < n; i++) {
  dp[i][i] = arr[i];
 }

// sum of elements from i to j:
// psum[j + 1] - psum[i]
 for (int i = n - 1; i >= 0; i--) {
  for (int j = 0; j < n; j++) {
    if (i > j) {
      dp[i][j] = 0;
      continue;
    }

    ll option_1 = arr[i] + (psum[j + 1] - psum[i + 1] - dp[i + 1][j]);
    ll option_2 = 0;
    if (j - 1 >= 0) option_2 = arr[j] + (psum[j] - psum[i] - dp[i][j-1]);
    dp[i][j] = max(option_1, option_2);
  }
 }

 ll p1 = dp[0][n - 1];
 ll p2 = psum.back() - p1;
 cout << p1 - p2;
 return 0;
}