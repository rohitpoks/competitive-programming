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
 int n;
 cin >> n;
 for (int i = 0; i < n; i++) {
  int l;
  cin >> l;
  string s;
  cin >> s;
  int res = 0;
  int t = 0;
  for (int j = 0; j < s.size(); j++) {
   if (s[j] != '*') t = 0;
   else t++;
   if (t == 2) break;
   if (s[j] == '@') res++;
  }
  cout << res << '\n';
 }
 return 0;
}