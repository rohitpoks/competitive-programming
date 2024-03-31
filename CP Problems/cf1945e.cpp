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
  int n; int x;
  cin >> n >> x;
  vector<int> arr(n);
  int x_pos = 0;
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
   if (arr[i] == x) x_pos = i;
  }
  int l = 0;
  int r = n;
  arr[x_pos] = arr[0];
  arr[0] = x;
  while (r - l != 1) {
   int m = (l+r)/ 2;
   if (arr[m] <= x) l = m;
   else r = m;
  }
  cout << "2\n";
  cout << "1 " << x_pos + 1 << '\n';
  cout << "1 " << l + 1 << '\n';
 }
 return 0;
}