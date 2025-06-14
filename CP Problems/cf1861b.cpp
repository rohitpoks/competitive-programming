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
#include <stack>
#include <cassert>

using ll = long long;
using uint = unsigned int;
using namespace std;

bool solve(string& x, string& y) {
  for (int i = 0; i < x.size() - 1; i++) {
    if (x[i] == '0' && x[i + 1] == '1' && y[i] == '0' && y[i + 1] == '1') return true;
  }

  return false;
}

// conjecture: if can make x = y, then max_1(x) == max_1(y)
// 000111000
// 000101010
int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  // pick i and try to make 
  string x, y;
  cin >> x >> y;
  if (solve(x, y)) cout << "YES\n";
  else cout << "NO\n";
 }
 return 0;
}