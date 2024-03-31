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
 int q;
 cin >> q;
 // map: every substring to a number
 // every substring to an instance set
 while (q--) {
  string s;
  cin >> s;
  int res = 0;
  for (int d = 1; d <= s.size() / 2; d++) {
   int l = 0;   
   int matches = 0;
   for (int i = 0; i <= d - 1; i++) {
    if (s[i] == s[i + d] || s[i] == '?' || s[i+d] == '?') matches++;
   }
   for (int r = d; r < s.size() - 1; r++) {
    if (matches == d) res = d;
    if (s[l] == s[r] || s[l] == '?' || s[r] == '?') matches--;
    if (r + d < s.size() && (s[r] == s[r+d] || s[r+d] == '?' || s[r] == '?')) matches++;
    l++;
   }
   if (matches == d) res = d;
  }
  cout << res * 2 << '\n';
 }
}