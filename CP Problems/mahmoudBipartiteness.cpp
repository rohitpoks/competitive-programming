#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <climits>

using ll = long long;
using namespace std;

void dfs(vector<vector<int> >& tree, ll& left, ll& right, int cur, int cur_set, set<int>& visited) {
 if (visited.count(cur) != 0) {
  return ;
 }

 visited.insert(cur);
 
 if (cur_set == 0) {
  left++;
  cur_set = 1;
 }
 else {
  right++;
  cur_set = 0;
 }
 for (int n : tree[cur]) {
  dfs(tree, left, right, n, cur_set, visited);
 }
}

int main() {
 ios_base::sync_with_stdio(false);
 ll n;
 cin >> n;

 vector<vector<int> > tree(n+1);
 for (int i = 0; i < n-1; i++) {
  int u;
  int v;
  cin >> u >> v;
  u--;
  v--;
  tree[u].push_back(v);
  tree[v].push_back(u);
 }
 ll l = 0;
 ll r = 0;
 set<int> visited;
 dfs(tree, l, r, 0, 0, visited);
 cout << l * r - (n-1);
 return 0;
}