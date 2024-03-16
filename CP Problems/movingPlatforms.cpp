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
int inv(int a, int m) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;
}

int edgeLength(int a, int b, int s1, int s2, int m) {
 int res = ((a-b)%m*inv((s2-s1)%m, m));
 return res;
}

ll dijkstras(vector<vector<pair<int, int> > >& graph, int start, int end, vector<int>& step, int m) {
 priority_queue<pair<int, int> > pq;
 pair<int, int> firstPair;
 firstPair.first = start;
 firstPair.second = 0;
 pq.push(firstPair);
 vector<int> distances(100005, -1);
 while (!pq.empty()) {
  pair<int, int> next = pq.top();
  pq.pop();
  // first time seeing this node, shortest path found
  distances[next.first] = next.second;
  if (next.first == end) break;
  for (pair<int, int> n : graph[next.first]) {
   if (distances[n.first] != -1) continue;
   pair<int, int> nodeForPQ;
   nodeForPQ.first = n.first;
   n.second = edgeLength(next.first, n.first, step[next.first], step[n.first], m);
   if (n.second == 0) continue;
   nodeForPQ.second = n.second + distances[next.first];  
   pq.push(nodeForPQ);
  }
 }
 return distances[end];
}
int main() {
 ios_base::sync_with_stdio(false);
 int z;
 cin >> z;
 for (int q = 0; q < z; z--) {
  int n, k, m;
  
  cin >> n >> k >> m;
  vector<int> init(n+1);
  vector<int> step(n+1);
  vector<vector<pair<int, int> > > graph(n+1);
  for (int i = 0; i < n; i++) {
   cin >> init[i];
  }
  for (int i = 0; i < n; i++) {
   cin >> step[i];
  }
  int min_length = INT_MAX;
  for (int i = 0; i < k; i++) {
   int a;
   int b;
   cin >> a >> b;
   pair<int, int> p1;
   pair<int, int> p2;
   p1.first = a;
   p2.first = b;
   graph[a].push_back(p2);
   graph[b].push_back(p1);
  }
  if (min_length == 0) {
   cout << "min length 0 for edge ";
   cout << -1;
   continue;
  }
  cout << dijkstras(graph, 1, n, step, m) << '\n';
 }
 return 0;
}