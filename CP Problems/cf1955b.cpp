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
  int n, c, d;
  cin >> n >> c >> d;
  vector<int> a;
  map<int, int> map;
  // increase row by c, col by d
  for (int i = 0; i < n * n; i++) {
   int x;
   cin >> x;
   a.push_back(x);
   if (map.find(x) == map.end()) {
    map[x] = 0;
   }
   map[x]++;
  }
  bool possible = true;
  int start = (*map.begin()).first;
  for (int i = 0; i < n; i++) {
   int next = start;
   for (int j = 0; j < n; j++) {
    if (map.count(next == 0) || map[next] == 0) {
     possible = false;
    }
    if (map.count(next) != 0) map[next]--;
    next = next + c;
   }
   start += d;
  }
  if (possible) cout << "YES\n";
  else cout << "NO\n";
 }
 return 0;
}