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
// incomplete solution
using ll = long long;
using namespace std;
int dfs(vector<vector<int> >& tree, int cur, int& count, int minSize, vector<bool>& visited, bool& res) {
 int size = 1; 
 if (visited[cur]) return 0;
 visited[cur] = true;
 for (int i : tree[cur]) {
  size += dfs(tree, i, count, minSize, visited, res);
 }
 if (size >= minSize && cur != 0) {
  // make cut here
  // cout << "made cut at vertex " << cur << endl;
  count--;
  return 0;
 }
 if (count <= 0) res = true;
 if (size < minSize) res = false;
 return size;
}
int main() {
 ios_base::sync_with_stdio(false);
 int q;
 cin >> q;
 while (q--) {
  int n, k;
  cin >> n >> k;
  vector<vector<int> > tree(n);
  for (int i = 0; i < n-1; i++) {
   int u; int v;
   cin >> u >> v;
   u--; v--;
   tree[u].push_back(v);
   tree[v].push_back(u);
  }
  int l = 0;
  int r = n;
  int ans = 0;
  while (l <= r) {
   int mid = (l + r)/2;
   vector<bool> visited(n, false);
   bool res = false;
   // cout << "ran dfs for " << mid << endl;
   int size = k;
   dfs(tree, 0, size, mid, visited, res);
   if (res) {
    // cout <<  "CHANGED ANS " << mid << endl;
    ans = mid;
    l = mid+1;
   }
   else r = mid-1;
  }
  cout << ans << '\n';
 }
 return 0;
}