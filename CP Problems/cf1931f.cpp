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

bool dfs(vector<set<int> >& graph, int cur, vector<int>& color) {
 // cycle detection
 color[cur] = 1;
 for (int i : graph[cur]) {
  if (color[i] == 1) {
   return true;
  }
  if (color[i] == 0) {
   if (dfs(graph, i, color)) return true;
  }
 }
 color[cur] = 2;
 return false;
}
int main() {
 ios_base::sync_with_stdio(false);
 int q;
 cin >> q;
 while (q--) {
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<set<int> > graph(n+1, set<int>());
  while (k--) {
   int a;
   int b;
   cin >> a;
   if (n > 1) cin >> b;
   for (int i = 0; i < n - 2; i++) {
    cin >> a;
    graph[b].insert(a);
    b = a;
   }
   
  }
  vector<int> color(n + 1, 0);
  bool ans = false;
  for (int i = 1; i <= n; i++) {
   if (color[i] == 0) ans = ans || dfs(graph, i, color);
  }
  if (ans) cout << "NO\n";
  else cout << "YES\n";

 }
 return 0;
}