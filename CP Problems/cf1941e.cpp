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


ll findOptimalBridge(vector<int>& arr, int d) {
 // dp[i]: if i were to build at i, what's the most optimal cosgt of doing so from 0 through i
 vector<ll> dp(arr.size(), 0);
 multiset<ll> set;
 dp[0] = 1;
 set.insert(1);
 for (int i = 1; i < arr.size(); i++) {
  if (i - d - 1 > 0) {
   set.erase(set.lower_bound(dp[i-d-2]));
  }
  dp[i] = arr[i] + 1 + (*set.begin());
  // cout << "dp at " << i << " is " << dp[i] << endl;
  // cout << "last erased was " << i-d-2 << " and min is " << (*set.begin()) << endl;
  set.insert(dp[i]);
 } 
 return dp[arr.size() - 1];
 // built at index - 1 already, need to build at 
}
int main() {
 ios_base::sync_with_stdio(false);

 int q;
 cin >> q;
 for (int z = 0; z < q; z++) {
  int n, m, k, d;
  cin >> n >> m >> k >> d;
  vector<vector<int> > water(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    cin >> water[i][j];
   }
  }
  vector<ll> res(n);
  // n = 5, k = 3
  // n = 0,1,2
  for (int i = 0; i < n; i++) {
   vector<ll> dp(m, -1);
   res[i] = findOptimalBridge(water[i], d);
  }
  ll cur = 0;
  for (int i = 0; i < k; i++) {
   cur += res[i];
  }
  ll out = cur;
  for (int i = k; i < n; i++) {
   cur += (res[i] - res[i-k]);
   out = min(cur, out);
  }
  cout << out << '\n';

 }
 return 0;
}