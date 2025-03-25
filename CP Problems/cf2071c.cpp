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
  int n, st, en;
  cin >> n >> st >> en;
  vector<vector<int> > tree(n + 1);
  // cout << "here" << endl;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
    // cout << "added edge " << u << "," << v << endl;
  }


  // root tree at en
  set<int> seen;
  queue<int> q;
  q.push(en);
  seen.insert(en);
  vector<vector<int > > level_traversal(n + 1);
  int level = 0;
  while (!q.empty()) {
    int s = q.size();
    for (int i = 0; i < s; i++) {
      int next = q.front();
      q.pop();
      // cout << "at node " << next << endl;
      level_traversal[level].push_back(next);
      for (int n : tree[next]) {
        // cout << "at negihbor " << n << endl;
        if (!seen.count(n)) {
          seen.insert(n);
          q.push(n);
        }
      }
    }


    level++;
  }

  vector<int> res;
  for (const auto& v : level_traversal) {
    for (int i : v) res.push_back(i);
  }

  for (int i = res.size() - 1; i >= 0; i--) {
    cout << res[i] << ' ';
  }

  cout << '\n';
 }

 return 0;
}