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

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  cout << n * 2 - 1 << '\n';
  cout << 1 << ' ' << 1 << ' ' << n << '\n';
  for (int i = 2; i <= n; i++) {
    cout << i << ' ' << 1 << ' ' << i - 1 << '\n';
    cout << i << ' ' << i << ' ' << n << '\n';
  }
 }
 return 0;
}