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

// return the minimum number of cuts, -1 if not possible
int dp(int index, vector<int>& arr, int rem, vector<vector<vector<int> > >& memo, bool is_first_connected) {
  // need to decide where to start and end cut
  if (index >= arr.size()) {
    if (rem == 0) return 0;
    return -1;
  }

  if (rem < 0) return -1;
  if (rem == 0) return 0;

  if (memo[index][rem][is_first_connected] != -2) return memo[index][rem][is_first_connected];
  int sum = 0;
  int res = INT_MAX;
  for (int end = index; end < arr.size(); end++) {
    sum += arr[end];
    int remaining_cuts = dp(end + 1, arr, rem - sum, memo, false);
    if (remaining_cuts > -1) {
      remaining_cuts += 1;
      remaining_cuts += is_first_connected;
      if (end == arr.size() - 1) remaining_cuts--;
      res = min(res, remaining_cuts);
    }

  }


  // option 2: don't cut
  int dc = dp(index + 1, arr, rem, memo, true);
  if (dc != -1) res = min(dc, res);
  
  return memo[index][rem][is_first_connected] = ((res == INT_MAX) ? -1 : res);
}

int main() {
 ios_base::sync_with_stdio(false);
 int k, n;
 while (1) {
  cin >> n >> k;
  if (n == 0 && k == 0) break;
  vector<int> arr(n);
  vector<vector<vector<int> > > memo(n, vector<vector<int > >(701, vector<int>(2, -2)));
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (k > 700) {
    cout << "IMPOSSIBLE" << '\n';
  } else {
    int res = dp(0, arr, k, memo, true);
    if (res == -1) cout << "IMPOSSIBLE" << '\n';
    else cout << res << endl;
  }
 }

 return 0;
}