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
  int t;
  cin >> t;
  while (t--) {
    int a; int b; int c; int d;
    cin >> a >> b >> c >> d;
    int res = a / 2;
    res += b / 2;
    res += c / 2;
    res += d / 2;
    res += ((a % 2 == 1) && (b % 2 == 1) && (c % 2 == 1));
    cout << res << '\n';
  }
  return 0;
}