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


int numberOfNodes(int root, vector<int>& res, vector<vector<int> >& tree) {
 int result = 1;
 for (int i : tree[root]) {
  result += numberOfNodes(i, res, tree);
 }
 return res[root] = result;
}
int main()
{
 vector<vector<int> > tree;
 int n;
 cin >> n;
 for (int i = 0; i < n; i++) {
  vector<int> inner;
  tree.push_back(inner);
 }

 for (int i = 1; i <= n-1; i++) {
  int parent;
  cin >> parent;
  parent--;
  tree[parent].push_back(i);
 }

 vector<int> res;
 for (int i = 0; i < n; i++) {
  res.push_back(0);
 }
 res[0] = numberOfNodes(0, res, tree);

 for (int i : res) {
  cout << (i - 1) << " ";
 }


 return 0;
}