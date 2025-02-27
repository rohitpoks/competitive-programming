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
  int ans = 7;
  int acc = 0;
  int mult = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (i == s.size() - 1) {
      // last digit
      int backward = s[i] - '7';
      if (backward < 0) backward += 10;
      ans = min(ans, backward);
      acc += mult * (s[i] - '0');
      mult *= 10;
      continue;
    }

    // calculate forward
    int forward = '7' - s[i];
    if (forward < 0) forward += 9;
    if (forward > acc) forward++;
    ans = min(ans, forward);

    // calculate special 8 case
    if (s[i] == '8') {
      int backward = 1;
      backward += acc;
      ans = min(ans, backward);
    }

    // cout << s[i] - '0' << endl;
    acc += mult * (s[i] - '0');
    mult *= 10;
    // cout << "acc is " << acc << endl;
  }
  
  cout << ans << '\n';
 }

 return 0;
}