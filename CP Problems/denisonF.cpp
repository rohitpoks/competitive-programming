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

int main() {
  
 ios_base::sync_with_stdio(false);
 int t = 0;
 while (1) {
  priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;
  // pq: (score, index (dist)), min heap
  t++;
  int n, m, k;
  cin >> n >> m >> k;
  for (int i  = 0; i < m; i++) {
    pq.push({0, i});
  }
  if (n == 0 && k == 0) {
    break;
  }

  vector<vector<int> > stacks(m);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    auto next = pq.top();
    pq.pop();
    stacks[next.second].push_back(k);
    next.first += k;
    pq.push(next);
  }

  int res = INT_MAX;
  for (const auto& stack: stacks) {
    int l = stack.size();
    for (int i = 0; i < l; i++) {
      int val = stack[i];
      if (val == k) {
        res = min(res,  l - 1 - i);
      }
    }

  }

  cout << "Case " << t << ": " << res << '\n';
 }

 return 0;
}