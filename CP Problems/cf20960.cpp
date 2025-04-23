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
  vector<int> res;
  res.push_back(0);
  int mi = 0;
  int ma = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '>') {
      // want next stick to be larger than all prev. sticks
      res.push_back(ma + 1);
      ma++;
    } else {
      res.push_back(mi - 1);
      mi--;
    }
  }
  

  for (int i : res) {
    cout << i - mi + 1 << ' ';
  }

  cout << endl;
 }
 return 0;
}