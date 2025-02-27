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
 string s;
 cin >> s;
 vector<int> lps(s.size(), 0);
 int prevLps = 0;
 int i = 1;

 while (i < s.size()) {
  if (s[i] == s[prevLps]) {
    lps[i] = prevLps + 1;
    prevLps++;
    i++;
  } else if (prevLps == 0) {
    lps[i] = 0;
    i++;
  } else {
    prevLps = lps[prevLps - 1];
  }
 }

 if (lps[s.size() - 1] > s.size() / 2) {
  cout << "YES" << '\n';
  cout << s.substr(s.size() - lps[s.size() - 1]);
 }
 else cout << "NO";
 return 0;
}