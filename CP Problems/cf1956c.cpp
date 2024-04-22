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
  ll n;
  cin >> n;
  vector<vector<ll> > a(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    a[i][j] = j + 1;
   }
  }
  int changed = 0;
  for (ll i = 0; i < n; i++) {
   if ((i+1) * n < (n * (n + 1))/2 && changed <= n) {
    changed++;
    for (int j = 0; j < n; j++) {
     a[j][i] = j + 1;
    }
   }
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    res += a[i][j];
   }
  }
  cout << res << ' ' << (changed + n) << '\n';
  for (int i = 0; i < n; i++) {
   cout << 1 << ' ' << (i + 1) << ' ';
   for (int j = 1; j <= n; j++) {
    cout << j << ' ';
   }
   cout << '\n';
  }
  for (int i = 0; i < changed; i++) {
   cout << 2 << ' ' << (i + 1) << ' ';
   for (int j = 1; j <= n; j++) {
    cout << j << ' ';
   }
   cout << '\n';
  }
 }
 return 0;
}