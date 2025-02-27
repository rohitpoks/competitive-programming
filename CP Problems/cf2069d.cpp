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
  string s;
  cin >> s;
  vector<bool> match(s.size(), 0);
  int l = 0;
  int r = s.size() - 1;
  set<int> no_matches;
  while (l < r) {
    match[l] = (s[l] == s[r]);
    match[r] = (s[l] == s[r]);
    if (!match[l]) {
      no_matches.insert(l);
      no_matches.insert(r);
    }
    l++;
    r--;
  }

  vector<int> rem(26, 0);
  for (int j = s.size() / 2; j < s.size(); j++) {
    if (match[j]) continue;
    // if no match, increase it's freq
    rem[s[j] - 'a']++;
  }

  int res = 0;
  int count = 0;
  int left_end = 0;
  for (int i : no_matches) {
    left_end = i + 1;
    if (i >= s.size() / 2) {
      left_end = i;
      break;
    }

    if (rem[s[i] - 'a']) {
      rem[s[i] - 'a']--;
    } else {
      // this means that there's nothing on the right that matches to this letter
      break;
    }

    count++;
  }

  if (no_matches.empty()) {
    cout << 0 << '\n';
    continue;
  }

  // cout << "left is " << left_end << endl;
  res = *(--no_matches.end()) - left_end + 1;
  cout << res << '\n';
 }
 return 0;
}