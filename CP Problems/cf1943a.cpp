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
 int q;
 cin >> q;
 while (q--) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  map<int, int> freq;
  for (int i : arr) {
   if (freq.count(i) == 0) freq[i] = 0;
   freq[i]++;
  }
  bool first_one = false;
  int ans = INT_MAX;
  for (int i = 0; i <= n; i++) {
   if (freq.count(i) == 0) ans = min(i, ans);
   if (freq[i] == 1) {
    if (!first_one) first_one = true;
    else ans = min(ans, i);
   }
  }
  cout << ans << '\n';
 }
 return 0;
}