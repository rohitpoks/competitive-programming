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
  vector<int> color(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> color[i];
  }

  vector<vector<int> > tree(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  vector<bool> res(n + 1, false);

  for (int i = 1; i <= n; i++) {
    // 1 step bfs from every node
    set<int> once;
    set<int> twice;
    once.insert(color[i]);
    for (int j : tree[i]) {
      int j_c = color[j];
      if (once.count(j_c)) {
        res[j_c] = true;
        // cout << "set color " << j_c << " to true at node " << i << endl;
      }
      else {
        once.insert(j_c);
      }
    }
  }

  for (int i = 1; i < res.size(); i++) {
    if (res[i]) cout << '1';
    else cout << '0';
  }

  cout << '\n';
 }
 return 0;
}