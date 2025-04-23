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
  int n;
  vector<pair<int, int> > pairs;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c1, c2;
    int x1, x2;
    cin >> c1 >> x1 >> c2 >> x2;
    if (c1 == '+') x1 *= -1;
    if (c2 == '+') x2 *= -1;
    pairs.push_back({x1, x2});
  }
  
  vector<pair<int, int> > dp_l(n);
  vector<pair<int, int> > dp_r(n);
  if (pairs[n-1].first < 0) {
    dp_l[n-1].first = 1;
    dp_l[n-1].second = -pairs[n-1].first;
  } else {
    dp_l[n-1].first = pairs[n-1].first;
    dp_l[n-1].second = 0;
  }

  if (pairs[n-1].second < 0) {
    dp_r[n-1].first = 1;
    dp_r[n-1].second = -pairs[n-1].second;
  } else {
    dp_r[n-1].first = pairs[n-1].second;
    dp_l[n-1].second = 0;
  }
 }
 return 0;
}