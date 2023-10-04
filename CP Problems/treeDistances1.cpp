#include <stdio.h>
#include <iostream>
#include <list>
#include <map>
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

int dist[2][200000];

void dfs2(vector<vector<int> >& tree, int cur, bool visited[], int distances[], int distance) {
 // cout << "at node " << cur << " and distance to endpoint is " << distance << endl;
 visited[cur] = true;
 for (int i : tree[cur]) {
  if (visited[i] > 0) continue;
  dfs2(tree, i, visited, distances, distance + 1);
 }
 distances[cur] = distance;
}

pair<int, int> dfs(vector<vector<int>> &tree, int cur, bool visited[])
{
 // returns {distance to node, node}
 visited[cur] = true;
 pair<int, int> resPair;
 resPair.first = 0;
 resPair.second = cur;
 for (int i : tree[cur])
 {
  if (visited[i])
   continue;
  pair<int, int> curRes = dfs(tree, i, visited);
  if (1 + curRes.first > resPair.first)
  {
   resPair = curRes;
   resPair.first += 1;
  }
 }
 return resPair;
}

int main() {
 vector<vector<int> > tree;
 int n;
 cin >> n;
 for (int i = 0; i < n; i++) {
  vector<int> cur;
  tree.push_back(cur);
 }
 int start = 0;
 for (int i = 1; i <= n - 1; i++) {
  int a;
  int b;
  cin >> a >> b;
  a--;
  b--;
  start = a;
  tree[a].push_back(b);
  tree[b].push_back(a);
 }
 bool visited[200000] = {0};
 pair<int, int> endP1 = dfs(tree, start, visited);
 bool visited2[200000] = {0};
 pair<int, int> endP2 = dfs(tree, endP1.second, visited2);
 bool visited3[200000] = {0};
 // cout << "to endpt " << endP1.second << endl;
 dfs2(tree, endP1.second, visited3, dist[0], 0);
 // cout << "to endpt" << endP2.second << endl;
 bool visited4[200000] = {0};
 dfs2(tree, endP2.second, visited4, dist[1], 0);

 for (int i = 0; i < n; i++) {
  cout << max(dist[0][i], dist[1][i]) << endl;
 }
 return 0;
}