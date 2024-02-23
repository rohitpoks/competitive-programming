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
// call b_search with {-1,n}
// returns {arr[l] < x <= arr[r] assuming indices are valid}
void b_search(vector<ll>& prefix, int m, int& l, int& r) {
 if (r == l + 1) return;
 int mid = l + (r-l)/2;
 // next line is pivotal, decides arr[l] < x <= arr[r]
 // (prefix[mid] <= m) l = mid would determine <= x <
 if (prefix[mid] >= m) r = mid; 
 else l = mid;
 b_search(prefix, m, l, r);
}

void solve() {
 vector<ll> reg;
 vector<ll> imp;
 int n;
 int m;
 cin >> n >> m;
 vector<int> apps;
 // set<ll> imp_set;
 for (int i = 0; i < n; i++) {
  int a;
  cin >> a;
  apps.push_back(a);
 }
 for (int i = 0;  i < n; i++) {
  int a;
  cin >> a;
  if (a == 1) reg.push_back(apps[i]);
  else imp.push_back(apps[i]);
 }
 // make prefix sum
 sort(reg.begin(), reg.end(), greater<ll>());
 sort(imp.begin(), imp.end(), greater<ll>());
 for (int i = 1; i < reg.size(); i++) {
  reg[i] += reg[i-1];
 }
 for (int i = 1; i < imp.size(); i++) {
  imp[i] += imp[i-1];
 }
 ll res = LONG_LONG_MAX;

 // bool skip = false;
 // if (imp.size() == 0) {
 //  skip = true;
 //  int l = -1;
 //  int r = reg.size();
 //  b_search(reg, m, l, r);
 //  if (r != reg.size()) res = r + 1;
 // }

 // if (reg.size() == 0) {
 //  int l = -1;
 //  int r = imp.size();
 //  b_search(imp, m, l, r);
 //  if (r != imp.size()) res = (r + 1)*2;
 // }

 
 for (int i = 0; i < reg.size(); i++) {
  // using i+1 reg apps
  int rem = m - reg[i];

  ll con = (i+1);
  int l = -1;
  int r = imp.size();
  b_search(imp, rem, l, r);
  
  // check if at the end of imp and rem non-zero
  if (r == imp.size() && rem > 0) continue;
  if (rem <= 0) r = -1;
  con += (r + 1) * 2;
  res = min(res, con);
 }
 int l = -1;
 int r = imp.size();
 b_search(imp, m, l, r);
 ll temp = (r + 1)*2;
 if (r != imp.size()) res = min(res, temp);
 if (res == LONG_LONG_MAX) cout << -1 << '\n';
 else cout << res << '\n';
}
int main() {
 ios_base::sync_with_stdio(false);
 int total;
 cin >> total;
 for (int t = 0; t < total; t++) {
  solve();
 }
 return 0;
}