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

class Node
{
public:
 int val;
 vector<Node *> neighbors;

 Node(int val)
 {
  this->val = val;
 }
};

pair<int, Node *> dfs(Node *currentNode, set<int> &visited, Node *start)
{
 // given a node, what's the longest path to a leaf, and what is the leaf?
 if (currentNode->neighbors.size() == 1 && currentNode != start)
  return {0, currentNode};
 visited.insert(currentNode->val);
 pair<int, Node *> maxPair = {0, currentNode};
 for (Node *neighbor : currentNode->neighbors)
 {
  if (visited.count(neighbor->val))
   continue;
  pair<int, Node *> curPair = dfs(neighbor, visited, start);
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
 map<int, Node *> nodeMap;
 if (tree.size() == 0)
  return 0;
 for (int i = 0; i < n; i++)
 {
  nodeMap.insert({i, new Node(i)});
 }

 for (int i = 0; i < tree.size(); i++)
 {
  int parent = tree[i][0];
  int child = tree[i][1];
  Node *p = nodeMap[parent];
  p->neighbors.push_back(nodeMap[child]);
  nodeMap[child]->neighbors.push_back(p);
 }

 Node *root = nodeMap[tree[0][0]];
 set<int> visited;
 pair<int, Node *> ans = dfs(root, visited, root);
 set<int> secondVisited;
 return dfs(ans.second, secondVisited, ans.second).first;
}

int main()
{
 int n;
 cin >> n;
 vector<vector<int>> tree;
 for (int i = 0; i < n - 1; i++)
 {
  int p;
  int c;
  cin >> p >> c;
  p--;
  c--;
  tree.push_back({p, c});
 }
 cout << solution(n, tree);
}
