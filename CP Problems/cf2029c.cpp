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

ll new_rating(ll cur, ll contest) {
  return cur + (contest > cur)  - (cur > contest);
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // max score possible if ratings 0, i and 0 -> before cut, 1 -> in cut, 2 -> after cut
  vector<vector<ll> > dp(n, vector<ll>(3, 0));
  // no cut yet so 1
  dp[0][0] = 1;
  // in cut: 0
  dp[0][1] = 0;
  // after cut-> cur cut so 0
  dp[0][1] = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      // no cut yet
      dp[i][0] = new_rating(dp[i - 1][0], arr[i]);

      // either start cut here or continue cut here
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);

      // cut indices previously
      dp[i][2] = max(new_rating(dp[i-1][1], arr[i]), new_rating(dp[i-1][2], arr[i]));

    }

    // cout << "at idx " << i << ": dp[0], dp[1], dp[2]: " << dp[i][0] << ", " << dp[i][1] << ", " << dp[i][2] << endl;
    // cout << endl;
  }

  cout << max(dp[n - 1][1], dp[n-1][2]) << '\n';
 }
 return 0;
}