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
  ll n, a, b;
  cin >> n >> a >> b;
  ll res = LLONG_MAX;
  res = min(a * n, b * (n/2) + (n % 2) * a);
  cout << res << '\n';
 }
 return 0;
}