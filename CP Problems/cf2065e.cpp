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
  if (abs(n - m) > k) {
    cout << "-1\n";
    continue;
  }

  if (k > n && k > m) {
    cout << "-1\n";
    continue;
  }
  int start;
  if (n > m) start = 0;
  else start = 1;

  while (n > 0 || m > 0) {
    if (start == 0) {
      int placement = min(k, n);
      for (int i = 0; i < placement; i++) cout << '0';
      n -= placement;
    } else {
      int placement = min(k, m);
      // cout << "placement is " << placement << endl;
      for (int i  = 0; i < placement; i++) cout << '1';
      m -= placement;
    }

    start += 1;
    start %= 2;
  }

  cout << '\n';
 }
 return 0;
}