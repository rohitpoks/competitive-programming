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

int mex(vector<int>& v1, vector<int>& coloring) {
  bool contains_0 = 0;
  bool contains_1 = 0;
  bool contains_2 = 0;
  for (int i : v1) {
    if (coloring[i] == 0) contains_0 = 1;
    if (coloring[i] == 1) contains_1 = 1;
    if (coloring[i] == 2) contains_2 = 1;
  }

  if (!contains_0) return 0;
  if (!contains_1) return 1;
  if (!contains_2) return 2;
  
  return 3;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, x, y;
  cin >> n >> x >> y;
  vector<vector<int> > adj(n + 1);
  for (int i = 1; i <= n; i++) {
    if (i + 1 <= n) adj[i].push_back(i + 1);
    else adj[i].push_back(1);

    if (i - 1 >= 1) adj[i].push_back(i-1);
    else adj[i].push_back(n);
  }

  adj[x].push_back(y);
  adj[y].push_back(x);

  vector<int> coloring(n+1, -1);
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    res.push_back(mex(adj[i], coloring));
    coloring[i] = res.back();
  }

  for (int i : res) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}