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
void b_search(int& l, int& r, vector<ll>& arr, ll find) {
 while (r - l> 1) {
  int mid = (l + r) / 2;
  if (find < arr[mid]) r = mid;
  else l = mid;
 }
}
int main() {
 ios_base::sync_with_stdio(false);
 int q;
 cin >> q;
 while (q--) {
  int n;
  cin >> n;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }

  vector<ll> prefix(n);
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
   prefix[i] = prefix[i-1] + arr[i];
  }
  int k;
  cin >> k;
  while (k--) {
   int l, u;
   cin >> l >> u;
   l--;
   ll find = u;
   if (l > 0)  find += prefix[l-1];
   int index = 0;
   int greater_than = n;
   b_search(index, greater_than, prefix, find);
   if (index + 1 < n && prefix[index + 1] - find <= find - prefix[index]) {
    index = index + 1;
   }
   cout << max(l + 1, index + 1) << ' ';
  }
  cout << '\n';
 }
 return 0;
}