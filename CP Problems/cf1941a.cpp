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
 int z;
 cin >> z;
 for (int q = 0; q < z; q++) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<int> b(m);
  
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
   cin >> b[i];
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    if (a[i] + b[j] <= k) res++;
   }
  }
  cout << res << '\n';
 }
}