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

vector<string> split(const string& s) {
  int begin = 0;
  vector<string> res;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      res.push_back(s.substr(begin, i - begin + 1));
      begin = i + 1;
    }
  }

  return res;
}

int solve(int n, int m, vector<string>& s) {
  vector<vector<string> > g(m, vector<string>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }

  // for every col, know if it's possible
  vector<bool> is_possible(n, false);
  vector<vector<bool> > matches(m, vector<bool>(n, false));
  int max_match_count = 0;
  // every row
  for (int j = 0; j < m; j++) {
    int cur_match_count = 0;
    // every col
    for (int i = 0; i < n; i++) {
      if (g[j][i] == s[i]) {
        is_possible[i] = true;
        matches[j][i] = true;
        cur_match_count++;
      }
    }

    max_match_count = max(cur_match_count, max_match_count);
  }

  for (bool i : is_possible) {
    if (!i) return -1;
  }

  return s.size() + (n - max_match_count) * 2;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  vector<string> s;
  for (int i = 0; i < n; i++) {
    string _;
    cin >> _;
    s.push_back(_);
  }

  cout << solve(n, m, s) << '\n';
 }
 return 0;
}