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
  int l, r;
  cin >> l >> r;
  if (l == r && r == 1) {
    cout << 1 << '\n';
    continue;
  }

  cout << r - l << '\n';
 }

 return 0;
}