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

  // every string of 10s -> 2 steps
  // 1010
  // 10, 10
  // 100, 1
  // empty, 1100
  // 00, 11
  int x;
  cin >> x;
  string s;
  cin >> s;
  int res  = 0;
  int prev = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] - '0' == prev) continue;
    // cout << "didnt continue at " << i << endl;
    if (s[i] - '0' == 0) {
      // went from 1 to 0
      res += 2;
      // cout << "inc at" << i << endl;
      prev = 0;
    } else {
      // went from 0 to 1
      // cout << "here" << endl;
      prev = 1;
    }
  }

  if (prev == 1) res++;
  cout << res << endl;
 }
 return 0;
}