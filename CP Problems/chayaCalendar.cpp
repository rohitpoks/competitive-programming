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
 int n;
 cin >> n;
 for (int i = 0; i < n; i++) {
  ll res = 0;
  int k;
  cin >> k;
  vector<int> p(k);
  for (int j = 0; j < k; j++) {
   cin >> p[j];
  }
  for (int j = 0; j < k; j++) {
   res += (p[j] - res % p[j]);
  }
  cout << res << '\n';
 }
 return 0;
}