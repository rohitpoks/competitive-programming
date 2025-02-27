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

ll MOD = 998244353;

ll dp(vector<int> arr) {
  // tail recursive
  vector<vector<int> > memo(arr.size() + 1, vector<int>(4, 0));
  for (int i = arr.size() - 1; i >= 0; i--) {
    for (int j = 3; j >= 1; j--) {
      if (arr[i] != j) {
        memo[i][j] = memo[i + 1][j];
      } else if (arr[i] == j && j == 3) {
        memo[i][j] = (1 + memo[i + 1][3]) % MOD;
      } else if (arr[i] == 2) {
        memo[i][j] = (memo[i + 1][j + 1] + (2 * memo[i + 1][j] % MOD)) % MOD;
      } else {
        memo[i][j] = (memo[i + 1][j + 1] + memo[i + 1][j]) % MOD;
      }
    }
  }

  return memo[0][1];
  // if (index >= arr.size()) return 0;

  // if (memo[index][look_for] != -1) return memo[index][look_for];

  // if (arr[index] != look_for) {
  //   return memo[index][look_for] = dp(arr, index + 1, look_for, memo) % MOD;
  // }

  // if (arr[index] == look_for && look_for == 3) {
  //   return memo[index][look_for] = (1 + dp(arr, index + 1, 3, memo)) % MOD;
  // }

  // if (arr[index] == 2) {
  //   return memo[index][look_for] = ((dp(arr, index + 1, look_for + 1, memo) % MOD) + (2 * (dp(arr, index + 1, look_for, memo)) % MOD) % MOD) % MOD;
  // }
  
  // return memo[index][look_for] = ((dp(arr, index + 1, look_for + 1, memo) % MOD) + (dp(arr, index + 1, look_for, memo)) % MOD) % MOD;
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << (dp(arr) % MOD) << '\n';
 }
 return 0;
}