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

pair<int, bool> maxMatching(int root, vector<vector<int> >& tree, set<int>& visited) {
 visited.insert(root);
 bool avail = true;
 int res = 0;
 for (int child : tree.at(root)) {
  if (visited.count(child) > 0) continue;
  pair<int, bool> cur = maxMatching(child, tree, visited);
  if (cur.second == true && avail == true) {
   avail = false;
   res += 1;
  }
  res += cur.first;
 }
 return {res, avail};
}

int main() {
 vector<vector<int> > tree;
 int n;
 cin >> n;
 int start = 0;
 for (int i = 0; i < n; i++) {
  vector<int> cur;
  tree.push_back(cur);
 }
 
 for (int i = 1; i <= n - 1; i++) {
  int a;
  int b;
  cin >> a;
  cin >> b;
  a--;
  b--;
  start = a;
  tree.at(a).push_back(b);
  tree.at(b).push_back(a);
 }
 set<int> visited;
 cout << maxMatching(start, tree, visited).first;

 return 0;

}