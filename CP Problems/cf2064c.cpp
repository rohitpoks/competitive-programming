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

ll dp(vector<ll>& a, int idx, bool is_last_neg, vector<vector<ll> >& memo) {
  if (idx >= a.size()) return 0;

  if (memo[idx][is_last_neg] != -1) return memo[idx][is_last_neg];

  if (a[idx] < 0) {
    return memo[idx][is_last_neg] = max(dp(a, idx + 1, is_last_neg, memo), dp(a, idx + 1, true, memo) + abs(a[idx]));
  }

  if (is_last_neg) {
    return memo[idx][is_last_neg] = dp(a, idx + 1, is_last_neg, memo);
  }

  return memo[idx][is_last_neg] = dp(a, idx + 1, is_last_neg, memo) + abs(a[idx]);
}
int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<ll> arr(n);
  vector<vector<ll> > memo(n, vector<ll>(2, -1));
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll cur = arr[0];
  vector<ll> a;
  for (int i = 1; i < n; i++) {
    if ((cur < 0 && arr[i] > 0) || (cur > 0 && arr[i] < 0)) {
      a.push_back(cur);
      cur = 0;
    }

    cur += arr[i];
  }

  a.push_back(cur);
  
  cout << dp(a, 0, false, memo) << '\n';
 }


 return 0;
}