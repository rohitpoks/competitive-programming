#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <climits>
#include <cassert>

// 4 5 1 2 3
// from 1 2 3 4 5
// 1 3 2 4 5
// 3 1 2 4 5
// 1 3 2 4 5
// 1 2 3 4 5
// 1 2 4 3 5
// 1 2 4 5 3
// 2 1 4 5 3
// 1 2 4 5 3
// 1 4 2 5 3
// 1 4 5 2 3
// done with 2
// 4 1 5 2 3
// 4 5 1 2 3
// 5 4 1 2 3
// 4 5 1 2 3
// 4 1 5 2 3
using ll = long long;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> order(n);
 vector<int> cur(n);
 vector<pair<int, int> > res;
 map<int, int> idx;
 for (int i = 0; i < n; i++) {
  cin >> order[i];
  cur[i] = i + 1;
  idx[i + 1] = i;
 }
 // {1, 3, 2} from {1, 2, 3}
 for (int i = order.size() - 1; i >= 0; i--) {
  int next = order[i];
  int max_idx = i;
  int cur_idx = idx[next];
  while (cur_idx > 0) {
    res.push_back({cur[cur_idx], cur[cur_idx - 1]});
    // swap this and one in front
    int t = cur[cur_idx];
    cur[cur_idx] = cur[cur_idx - 1];
    cur[cur_idx - 1] = t;

    // reflect in idx
    idx[cur[cur_idx]] = cur_idx;
    idx[cur[cur_idx - 1]] = cur_idx - 1;
    cur_idx--;
  }

  while (cur_idx < max_idx) {
    res.push_back({cur[cur_idx + 1], cur[cur_idx]});
    // swpa this and one behind
    int t = cur[cur_idx];
    cur[cur_idx] = cur[cur_idx + 1];
    cur[cur_idx + 1] = t;

    // reflect in idx
    idx[cur[cur_idx]] = cur_idx;
    idx[cur[cur_idx + 1]] = cur_idx + 1;
    cur_idx++;
  }
 }

 cout << res.size() << '\n';
 for (auto& p : res) {
  cout << p.first << ' ' << p.second << '\n';
 }

 return 0;
}