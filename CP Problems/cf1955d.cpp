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
 int t;
 cin >> t;
 while (t--) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<int> b(m);
  map<int, int> remaining;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
   cin >> b[i];
   if (remaining.count(b[i]) == 0) remaining[b[i]] = 0;
   remaining[b[i]]++;
  }
  int matches = 0;
  for (int i = 0; i < m; i++) {
   if (remaining.count(a[i]) > 0) {
    remaining[a[i]]--;
    if (remaining[a[i]] >= 0) matches++;
   }
  }
  // cout << "initial match: " << matches << endl;
  // cout << "printing remaining: " << endl;
  // for (auto i: remaining) {
  //  cout << i.first << ":" << " " << i.second << endl;
  // }
  int res = matches >= k ? 1 : 0;
  for (int i = m; i < n; i++) {
   // add a[i], remove[a[i-m]]
   if (remaining.count(a[i-m]) > 0) {
    remaining[a[i-m]]++;
    if (remaining[a[i-m]] > 0) matches--;
   }
   if (remaining.count(a[i]) > 0) {
    remaining[a[i]]--;
    if (remaining[a[i]] >= 0) matches++;
   }
   if (matches >= k) res++;
   // cout << "matches is " << matches << endl;
   // cout << "increased res at position " << i << "\n";
  }
  cout << res << "\n";
 }
 return 0;
}