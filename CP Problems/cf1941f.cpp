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
 int q;
 cin >> q;
 for (int z = 0; z < q; z++) {
  int n; int m; int k;
  cin >> n >> m >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  // find largest difference
  int l = 0;
  int r = 1;
  for (int j = 1; j < n; j++) {
   if (abs(arr[j] - arr[j-1]) > abs(arr[r] - arr[l])) {
    l = j-1;
    r = j;
   }
  }
  vector<int> d(m);
  vector<int> f(k);
  for (int i = 0; i < m; i++) {
   cin >> d[i];
  }
  for (int i = 0; i < k; i++) {
   cin >> f[i];
  }
  // find d[j]+f[k] closest to midpoint of arr[l],arr[r]
  set<ll> set;
  for (int i : f) {
   set.insert(i);
  }
  ll cur_ans = abs(arr[l] - arr[r]);
  ll midpoint = arr[l] + (arr[r] - arr[l])/2;
  for (int i = 0; i < m; i++) {
   ll looking_for = midpoint - d[i];
   auto next = set.lower_bound(looking_for);
   if (next != set.end()) {
    cur_ans = min(cur_ans, max(abs((*next + d[i])- arr[l]), abs((*next+d[i]) - arr[r])));
   }
   
   if (next != set.begin()) {
    next--;
    cur_ans = min(cur_ans, max(abs((*next + d[i]) - arr[l]), abs((*next + d[i])-arr[r])));
   }
  }
  for (int i = 0; i < arr.size() - 1; i++) {   
   if (i == l) {
    cur_ans = min(cur_ans, (ll) abs(arr[i] - arr[i+1]));
    continue;
   }
   cur_ans = max(cur_ans, (ll) abs(arr[i] - arr[i+1]));
  }
  cout << cur_ans << '\n';
 } 
 return 0;
}