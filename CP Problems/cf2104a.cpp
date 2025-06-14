#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <climits>
#include <cassert>

using ll = long long;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int a, b, c;
  cin >> a >> b >> c;
  int res = c - (b - a);
  if ((res - b >= 0) && ((res-b) % 3 == 0)) cout << "YES\n";
  else cout << "NO\n";
 }
 return 0;
}