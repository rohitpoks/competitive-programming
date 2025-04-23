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

int solve(const string& s) {
  int num_groups = 1;

  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1]) {
      num_groups++;
    }
  }

  // cout << "num_grps is " << num_groups << endl;
  if (num_groups == 1) {
    if (s[0] == '1') return 1 + s.size();
    else return s.size();
  } else if (num_groups == 2) {
    return 1 + s.size();
  } else if (num_groups == 3) {
    return 1 + s.size();
  } else {
    if (s[0] == '1') return s.size() + num_groups - 2;
    return s.size() + num_groups - 3;
  }
}

int num_ops(const string& s) {
  int num_grps = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i-1]) num_grps++;
  }

  if (s[0] == '1') return s.size() + num_grps;
  else return s.size() + num_grps - 1;
}

int test(const string& s) {
  int global_min = INT_MAX;
  for (int i  = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      string t = s;
      // reverse t from i to j
      int l = i;
      int r = j;
      while (l < r) {
        char c = t[l];
        t[l] = t[r];
        t[r] = c;
        l++;
        r--;
      }

      // cout << "now testing " << t << endl;
      // cout << "ans is " << num_ops(t) << endl;
      global_min = min(global_min, num_ops(t));
    }
  }

  return global_min;
}

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
  cout << solve(s) << '\n';
 }

// while (1) {
//   string s = "";
//   for (int i = 0; i < 5; i++) {
//     int r = rand() % 2;
//     s += (r) + '0';
//   }

//   cout << "s is " << s << endl;
//   if (test(s) != solve(s)) {
//     cout << "error!";
//     break;
//   }
// }

//  string s = "11001";
//  cout << solve(s) << endl;
//  cout << test(s) << endl;
 return 0;
}