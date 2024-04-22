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
  cin >> n;
  string s;
  cin >> s;
  int res = 1;
  for (int k = 2; k <= n; k++) {   
   int maxInv = n + 1;
   int invCount = 0;
   set<int> sub;
   
   for (int i = 0; i < n; i++) {
    if (s[i] == '1' && invCount % 2 == 1 && maxInv >= i) {
     // this is a zero, need to invert
     sub.insert(i+k-1);
     invCount++;
    } else if (s[i] == '0' && invCount % 2 == 0 && maxInv >= i) {
     sub.insert(i + k - 1);
     invCount++;
    }
    if (sub.count(i) > 0) invCount--;
   }
   if (sub.size() == 0 || (*(--sub.end()) < n)) res = k;
  }
  cout << res << "\n";
 }
 return 0;
}