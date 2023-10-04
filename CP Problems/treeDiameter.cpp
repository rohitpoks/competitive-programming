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

pair<int, int> dfs(int currentNode, set<int> &visited, int start, vector<vector<int>> &graph)
{
 // given a node, what's the longest path to a leaf, and what is the leaf?
 if (graph[currentNode].size() == 1 && currentNode != start)
  return {0, currentNode};
 visited.insert(currentNode);
 pair<int, int> maxPair = {0, currentNode};
 for (int neighbor : graph[currentNode])
 {
  if (visited.count(neighbor) > 0)
   continue;
  pair<int, int> curPair = dfs(neighbor, visited, start, graph);
  if (curPair.first + 1 > maxPair.first)
  {
   maxPair = curPair;
   maxPair.first += 1;
  }
 }
 return maxPair;
}

int solution(int n, vector<vector<int>> tree)
{
 vector<vector<int>> graph;
 if (tree.size() == 0)
  return 0;
 for (int i = 0; i < n; i++)
 {
  graph.push_back({});
 }

 for (int i = 0; i < tree.size(); i++)
 {
  int a = tree[i][0];
  int b = tree[i][1];
  graph[a].push_back(b);
  graph[b].push_back(a);
 }
 int root = graph[0][0];
 set<int> visited;
 pair<int, int> ans = dfs(root, visited, root, graph);
 set<int> secondVisited;
 return dfs(ans.second, secondVisited, ans.second, graph).first;
}

int main() {
 int n;
 cin >> n;
 vector<vector<int> > tree;
 for (int i = 0; i < n - 1; i++) {
  int p;
  int c;
  cin >> p >> c;
  p--;
  c--;
  tree.push_back({p, c});
  
 }
 cout << solution(n, tree);
}

