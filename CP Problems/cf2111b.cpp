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
using namespace std;

pair<int, int> fib(int n) {
  if (n == 1) return {0, 1};
  int a = 1;
  int b = 2;
  for (int i = 3; i <= n; i++) {
    int t = b;
    b = a + b;
    a = t;
  }

  return {a, b};
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    vector<int> sides(3);
    cin >> sides[0] >> sides[1] >> sides[2];
    sort(sides.begin(), sides.end());
    // as long as largest two fit
    const auto [a, b] = fib(n);
    if (a + b <= sides[2] && b <= sides[1] && b <= sides[0]) cout << 1;
    else cout << 0;
  }

  cout << '\n';
 }
 return 0;
}