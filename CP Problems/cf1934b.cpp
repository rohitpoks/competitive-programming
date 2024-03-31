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
  ll ans = 0;
  if (n % 15 == 5 && n >= 15) ans = -2;
  if (n % 15 == 8 && n >= 15) ans = -1;
  if (n % 15 == 12) ans = -1;
  ans += (n / 15);
  n -= 15 * (n/15);
  ans += n/10;
  n -= 10 * (n/10);
  ans += n/6;
  n -= 6 * (n/6);
  ans += n/3;
  n -= 3 * (n/3);
  ans += n/1;
  n -= n/1;
  cout << ans << '\n';
 }
 return 0;
}