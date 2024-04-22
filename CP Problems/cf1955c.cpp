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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  int l = 0;
  int r = n - 1;
  bool left = true;
  int res = 0;
  while (l <= r && k >= 0) {
   if (left && k >= a[l]) {
    k -= a[l];
    left = false;
    l++;
    res++;
   } else if (!left && k >= a[r]){
    k -= a[r];
    left = true;
    r--;
    res++;
   } else {
    break;
   }
  }
  cout << res << "\n";
 }
 return 0;
}