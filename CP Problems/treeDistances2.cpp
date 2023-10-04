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

long long getLowerLevel(long long root, vector<vector<long long> >& tree, int parent, vector<long long>& lowerLevel, vector<long long>& nodeCount) {
 long long res = 0;
 for (long long i : tree[root]) {
  if (i != parent) res += nodeCount[i];
  
 }
 for (long long i : tree[root]) {
  if (i != parent) res += getLowerLevel(i, tree, root, lowerLevel, nodeCount);
 } 
 return lowerLevel[root] = res;
}
long long getNodeCount(long long root, vector<vector<long long> >& tree, int parent, vector<long long>& nodeCount) {
 long long res = 0;
 for (long long i : tree[root]) {
  if (i != parent) res += getNodeCount(i, tree, root, nodeCount);
 }
 return nodeCount[root] = (res + 1);
}

int main() {
 long long n;
 cin >> n;
 vector<vector<long long> >tree(n, vector<long long>());
 for (int i = 0; i < n-1; i++) {
  long long a;
  long long b;
  cin >> a;
  cin >> b;
  a--;
  b--;
  tree[a].push_back(b);
  tree[b].push_back(a);
 }
 vector<long long> nodeCount(n, 0);
 getNodeCount(0, tree, -1, nodeCount);
 vector<long long> lowerLevel(n, 0);
 getLowerLevel(0, tree, -1,lowerLevel, nodeCount);
 vector<long long> result(n, 0);
 result[0] = lowerLevel[0];
 queue<long long> queue;
 vector<bool> visited(n, false);
 queue.push(0);
 vector<long long> cToP(n, -1);

 while (!queue.empty()) {
  long long s = queue.size();
  for (long long i = 0; i < s; i++) {
   long long latest = queue.front();
   queue.pop();
   visited[latest] = true;
   if (cToP[latest] != -1) {
    result[latest] = ((long long) n + result[cToP[latest]] - 2 * (long long) nodeCount[latest]);
   } 

   for (long long i : tree[latest]) {
    if (!visited[i]) {
     cToP[i] = latest;
     visited[i] = true;
     queue.push(i);
    }
   }
  }
 }
 // root the tree at 0
 for (long long i : result) {
  cout << i << ' ';
 }
 return 0;
}