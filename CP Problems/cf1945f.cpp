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
 while (q--) {
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].first;
   a[i].second = i;
  }
  for (int i = 0; i < n; i++) {
   cin >> b[i];
   b[i]--;
  }
  set<int> avail;
  for (pair<int, int>& i : a) {
   avail.insert(i.first);
  }
  
 }
 return 0;
}