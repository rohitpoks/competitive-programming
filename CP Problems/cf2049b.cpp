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
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int> > intervals;
  for (int i = 0; i < n; i++) {
    if (s[i] == 's') intervals.push_back({n - 1 - i, i, n - 1});
    if (s[i] == 'p') intervals.push_back({i, 0, i});
  }

  bool is_possible = true;
  sort(intervals.begin(), intervals.end(), greater<vector<int> >());
  if (intervals.size() == 0) {
    cout << "YES\n";
    continue;
  }

  int l = intervals[0][1];
  int r = intervals[0][2];
  for (const auto& interval : intervals) {
    // cout << interval[1] << "." << interval[2] << endl;
    if (interval[1] < l) is_possible = false;
    else if (interval[2] > r) is_possible = false;
    l = max(l, interval[1]);
    r = min(r, interval[2]);
  }
  if (!is_possible) cout << "NO\n";
  else cout << "YES\n";
 }
 return 0;
}