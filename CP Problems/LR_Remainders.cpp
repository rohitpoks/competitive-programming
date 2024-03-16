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
// returns post-order completion: first calculate result from inner l,r, and then apply the operation on the current index
ll solve(int i, int l, int r, string& s, vector<int>& arr, int m, vector<ll>& ans) {
 if (l == r) {
  ans.push_back(arr[l]%m);
  return ans[0];
 }
 ll res;
 if (s[i] == 'L') {
  res = solve(i + 1, l + 1, r, s, arr, m, ans);
  res *= arr[l];
 } else {
  res = solve(i+1, l, r - 1, s, arr, m, ans);
  res *= arr[r];
 }
 res %= m;
 ans.push_back(res);
 return res;
}

int main() {
 ios_base::sync_with_stdio(false);
 int z;
 cin >> z;
 for (int q = 0; q < z; q++) {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  string s;
  cin >> s;
  vector<ll> ans;
  solve(0, 0, n-1, s, arr, m, ans);
  reverse(ans.begin(), ans.end());
  for (ll j : ans) {
   cout << j << ' ';
  }
  cout << '\n';
 }
 return 0;
}