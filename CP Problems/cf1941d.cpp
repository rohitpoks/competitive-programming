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

void solve(vector<pair<int, int> >& throws, int index, int cur_ball, int n) {
 set<int> res;
 res.insert(cur_ball);
 set<int> next;
 
 for (pair<int, int> p : throws) {
  // for every throw, calculate the next set
  for (int i : res) {
   if (p.second == 0 || p.second == -1) {
    next.insert((i + p.first) % n);
   }
   if (p.second == 1 || p.second == -1) {
    int val = (i - p.first) % n;
    if (val < 0) val += n;
    next.insert(val);
   }
  }
  res = next;
  next = set<int>();
 }

 cout << res.size() << '\n';
  auto iter = res.begin();
  while (iter != res.end()) {
   cout << (*iter) + 1 << ' ';
   iter++;
  }
  cout << '\n';
}

int main() {
 ios_base::sync_with_stdio(false);
 int z;
 cin >> z;
 for (int q = 0; q < z; q++) {
  int m, n, x;
  cin >> n >> m >> x;
  vector<pair<int, int> > throws;
  for (int i = 0; i < m; i++) {
   int dist;
   char type;
   cin >> dist;
   cin >> type;
   pair<int, int> p;
   p.first = dist;
   if (type == '0') {
    p.second = 0;
    throws.push_back(p);
   } else if (type == '1') {
    p.second = 1;
    throws.push_back(p);
   } else {
    p.second = -1;
    throws.push_back(p);
   }
  }
  solve(throws, 0, x - 1, n);
 }
 return 0;
}